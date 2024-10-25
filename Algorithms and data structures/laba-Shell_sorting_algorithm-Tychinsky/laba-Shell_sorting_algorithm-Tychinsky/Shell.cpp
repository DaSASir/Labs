#include <iostream>
#include <fstream>//файлы
#include <time.h>//время
#include <cmath>//для логарифмов
#include <vector>
#include "Shell.h"

//#1
void TheInitialSequence(int* a, const int n) {
	std::vector<int> h;

	for (int i = n / 2; i >= 1; i /= 2)
		h.push_back(i);

	ShellAlgorithm(h.size(), h.data(), a, n);
}

void ShellAlgorithm(int t, int* h, int* a, int n) {
	for (int i = 0; i <= t; i++) {
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

bool IsOrderly(int* mas_cheese, int n) {
	for (int i = 0; i < n - 1; i++) 
		if (mas_cheese[i] > mas_cheese[i])
			return false;
	
	return true;
}

//#2
int** CreateDiffArrays() {
	srand((unsigned int)time(0));

	FILE* f;
	fopen_s(&f, "Arrays.txt", "w");
	if (f == NULL) { perror("error opening file"); exit(-1); }

	int size[] = { 10000 ,10000 ,10000 ,
				   100000 ,100000 ,100000 ,
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
	std::vector<int> h;

	for (int m = 1; m <= (int)log2(n); m++)
		h.push_back((int)pow(2, m) - 1);

	ShellAlgorithm(h.size(), h.data(), a, n);
}
void TheWhipSequence(int* a, const int n) {//Кнут
	std::vector<int> h;

	int h_1 = 1;
	while (h_1 < n) {
		h.push_back(h_1);
		h_1 = 3 * h_1 + 1;
	}

	ShellAlgorithm(h.size(), h.data(), a, n);
}
void TheSedgwickSequence(int* a, const int n) {
	std::vector<int> h;
	int t = 1;

	while (true) {
		int h_1;
		if (t % 2 == 0) 
			h_1 = 9 * pow(2, t / 2) - 9 * pow(2, t / 2) + 1;
		else
			h_1 = 8 * pow(2, (t + 1) / 2) - 6 * pow(2, (t + 1) / 2) + 1;

		if (h_1 >= n) break;
		h.push_back(h_1);
		t++;
	}

	ShellAlgorithm(h.size(), h.data(), a, n);
}