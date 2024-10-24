#include <iostream>
#include <fstream>
#include <time.h>
#include "Shell.h"

//#1
void ShellAlgorithm(int* mas_cheese,const int n) {
	int h = n / 2;//шаги
	while ( h > 1 ) {
		for (int i = h; i < n; i++) {
			int x = mas_cheese[i];//берем сразу второй элемент

			int j = i;
			while (j >= h && mas_cheese[j - h] > x) {//проверяем второй элемент с первым
				mas_cheese[j] = mas_cheese[j - h];
				j -= h;
			}
			mas_cheese[j] = x;
		}
		h /= 2;
	}
}

void PrintArray(int* mas_cheese, const int n) {
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

	int** cheese = new int*[9];
	for (int i = 0; i < 9; i++) {
		if (i >= 0 && i < 3)
			cheese[i] = new int[10000];
		else if (i >= 3 && i < 6)
			cheese[i] = new int[100000];
		else if (i >= 6 && i < 9)
			cheese[i] = new int[1000000];

		if (i == 0 || i == 3 || i == 6) {
			for (int j = 0; j < 9; j++) {
				cheese[i][j] = rand() % (10 - (-10) + 1) + (-10);
				fprintf(f, "%d ", cheese[i][j]);
			}
			fprintf(f, "\n\n");
		}
				
		else if (i == 1 || i == 4 || i == 7) {
			for (int j = 0; j < 9; j++) {
				cheese[i][j] = rand() % (1000 - (-1000) + 1) + (-1000);
				fprintf(f, "%d ", cheese[i][j]);
			}
			fprintf(f, "\n\n");
		}
		
				
		else if (i == 2 || i == 5 || i == 8) {
			for (int j = 0; j < 9; j++) {
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

double CreateAverageTime(int** cheese) {
	double average_time = 0;
	for (int step = 0; step < 9; step++) {
		clock_t start_time, stop_time;//начинаем считать время
		start_time = clock();

		if (step >= 0 && step < 3)
			ShellAlgorithm(cheese[step], 10000);
		else if (step >= 3 && step < 6)
			ShellAlgorithm(cheese[step], 100000);
		else if (step >= 6 && step < 9)
			ShellAlgorithm(cheese[step], 1000000);
		

		stop_time = clock();//заканчиваем считать время
		average_time += (double)(stop_time - start_time) / CLOCKS_PER_SEC;
	}
	

	return (average_time / 9);
}