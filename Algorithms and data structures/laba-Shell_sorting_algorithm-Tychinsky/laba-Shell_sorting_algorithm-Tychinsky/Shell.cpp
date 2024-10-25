#include <iostream>
#include <fstream>//файлы
#include <time.h>//время
#include <cmath>//для логарифмов
#include <vector>
#include "Shell.h"

//#1
void TheInitialSequence(int* a, const int n) {
	int t = 0;//кол-во шагов
	for (int i = n / 2; i > 1; i /= 2)
		t++;

	int* h = new int[t + 1];//массив шагов
	for (int i = n / 2, j = 0; i >= 1 && j <= t; i /= 2, j++)
		h[j] = i;

	ShellAlgorithm(t, h, a, n);

	delete[]h;
}

void ShellAlgorithm(int t, int* h, int* a, int n) {
	for (int i = 0; i <= t; i++) {//Алгоритм Шелла
		int s = h[i];
		for (int b = 0; b < s; b++) {//Вставка для подпоследовательности
			for (int j = b + s; j < n; j += s) {
				int x = a[j];
				int k = j - s;
				while (k >= 0 && a[k] > x) {
					a[k + s] = a[k];
					k -= s;
				}
				a[k + s] = x;
			}
		}
	}
}

void PrintArray(int mas_cheese[], const int n) {
	for (int i = 0; i < n; i++)
		std::cout << mas_cheese[i] << " ";
}

bool IsOrderly(int* mas_cheese, const int n) {
	return n < 2 ? 1 : (mas_cheese[n - 2] > mas_cheese[n - 1] ? 0 : IsOrderly(mas_cheese, n - 1));
}

//#2
int** CreateDiffArrays() {
	srand((unsigned int)time(0));

	FILE* f;
	fopen_s(&f,"Arrays.txt", "w");
	if (f == NULL) { perror("error opening file"); exit(-1); }

	int size[] = { 10000 ,10000 ,10000 ,
				   100000 ,100000 ,100000,
				   1000000 ,1000000 ,1000000 };

	int** cheese = new int*[9];
	for (int i = 0; i < 9; i++) {
		cheese[i] = new int[size[i]];

		if (i == 0 || i == 3 || i == 6) {
			for (int j = 0; j < size[i]; j++) {
				cheese[i][j] = rand() % (10 - (-10) + 1) + (-10);
				fprintf(f, "%d ", cheese[i][j]);
			}
			fprintf(f, "\n\n");
		}
				
		else if (i == 1 || i == 4 || i == 7) {
			for (int j = 0; j < size[i]; j++) {
				cheese[i][j] = rand() % (1000 - (-1000) + 1) + (-1000);
				fprintf(f, "%d ", cheese[i][j]);
			}
			fprintf(f, "\n\n");
		}
				
		else if (i == 2 || i == 5 || i == 8) {
			for (int j = 0; j < size[i]; j++) {
				cheese[i][j] = rand() % (100000 - (-100000) + 1) + (-100000);
				fprintf(f, "%d ", cheese[i][j]);
			}
			fprintf(f, "\n\n");
		}		
	}
	fclose(f);
	return cheese;
}

void DeleteMatrix(int** a,const int n) {
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[]a;
}

//другие формулы для выбора длин шагов в алгоритме Шелла
void SequenceWithLogarithms(int* a, const int n) {
	int t = (int)log2(n);//кол-во шагов

	int* h = new int[t];//массив шагов
	for (int m = 1; m <= t; m++)
		h[m - 1] = pow(2, m) - 1;

	ShellAlgorithm(t, h, a, n);

	delete[]h;
}
void TheWhipSequence(int* a, const int n) {//Кнут
	int t = 0;//кол-во шагов
	int h_1 = 1;
	while (h_1 < n) {
		t++;
		h_1 = 3 * h_1 + 1;
	}

	int* h = new int[t];//массив шагов
	h_1 = 1;
	for (int i = 0; i < t; i++) {
		h[i] = h_1;
		h_1 = 3 * h_1 + 1;
	}

	ShellAlgorithm(t, h, a, n);

	delete[]h;
}
void TheSedgwickSequence(int* a, const int n) {
	int t = 0;//кол-во шагов
	int h_1 = 0;
	while (h_1 < n) {
		t++;
		if (t % 2 == 0) 
			h_1 = 9 * pow(2, t / 2) - 9 * pow(2, t / 2) + 1;
		else
			h_1 = 8 * pow(2, (t + 1) / 2) - 6 * pow(2, (t + 1) / 2) + 1;
	}

	int* h = new int[t];//массив шагов
	h_1 = 1;
	for (int j = 0; j < t; j++) {
		if(j%2 ==0)
			h[j] = 9 * pow(2, j / 2) - 9 * pow(2, j / 2) + 1;
		else
			h[j] = 8 * pow(2, (j + 1) / 2) - 6 * pow(2, (j + 1) / 2) + 1;
	}

	ShellAlgorithm(t, h, a, n);

	delete[]h;
}

//нахождение среднего времени
std::vector<double> CreateAverageTime(int** diff_array) {
	std::vector<double> cheese(4, 0.0);

	for (int i = 0; i < 4; i++) {
		double time = 0.0;
		int** copy = diff_array;
		for (int j = 0; j < 9; j++) {
			time_t start_time = clock();

			if (i == 0)
				TheInitialSequence(copy[j], 9);
			else if(i == 1)
				SequenceWithLogarithms(copy[j], 9);
			else if(i == 2)
				TheWhipSequence(copy[j], 9);
			else if(i == 3)
				TheSedgwickSequence(copy[j], 9);

			time_t stop_time = clock();
			time += (double)(stop_time - start_time) / CLOCKS_PER_SEC;
		}

		for (int k = 0; k < 9; k++)
			delete[] copy[k];
		delete[] copy;

		cheese[i] = time / 9;
	}

	return cheese;
};