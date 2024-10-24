#include <iostream>
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