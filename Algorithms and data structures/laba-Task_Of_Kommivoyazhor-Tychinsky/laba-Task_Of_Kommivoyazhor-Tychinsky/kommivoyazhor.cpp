#include <iostream>
#include <time.h>
#include "kommivoyazhor.h"

using namespace std;

void CreateMatrixCities(int** matrix, const int gauge, const int max_number, const int min_number) {
	srand((unsigned int)time(0));
	for (int i = 0; i < gauge; i++)
		matrix[i] = new int[gauge];

	for (int i = 0; i < gauge; i++)
		for (int j = 0; j < gauge; j++) {
			if (i == j)
				matrix[i][j] = 0;
			else
				matrix[i][j] = rand() % (max_number - min_number + 1) + min_number;
		}
}
void DeleteMatrixCities(int** matrix, const int gauge) {
	for (int i = 0; i < gauge; i++)
		delete[] matrix[i];
	delete[]matrix;
}
void Print(int** matrix, const int gauge) {
	for (int i = 0; i < gauge; i++) {
		for (int j = 0; j < gauge; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}
int CreateEntryCity(int gauge) {
	int entry_city;
	cout << endl << "Введите начальный город: ";
	cin >> entry_city;
	while (entry_city < 1 || entry_city > gauge) {
		cout << "Введите еще раз начальный город: ";
		cin >> entry_city;
	}return entry_city;
}

//функции для путей
int** CreatePathMatrix(int gauge, int entry_city, int amount_of_path) {
	int** path = new int* [amount_of_path];
	for (int i = 0; i < amount_of_path; i++)
		path[i] = new int[gauge + 1];

	
	for (int i = 0; i < amount_of_path; i++) {
		int cheese = 1;
		for (int j = 0; j < gauge + 1; j++) {
			if (j == 0 || j == gauge)
				path[i][j] = entry_city;
			else {
				if (cheese != entry_city && cheese <= gauge) {
					path[i][j] = cheese;
					cheese++;
				}
				else {
					cheese++;
					path[i][j] = cheese;
					cheese++;
				}
			}
		}
	}

	for (int i = 1; i < amount_of_path; i++) {
		for (int j = 1; j < gauge; j++)
			path[i][j] = path[i - 1][j];

		AlgorithmDijkstra(path[i], gauge);
	}

	return path;
}

void AlgorithmDijkstra(int* P, int n) {
	/*1. Находим максимальное значение i такое, что
	0 < i < n и P[i] < P[i+1]. Если такого i не
	существует, то процесс завершен – следующей
	перестановки нет, иначе п.2.*/
	int i = -1;
	for (int a = n - 2; a >= 0; a--) {
		if (P[a] < P[a + 1]) {
			i = a;
			break;
		}
	}

	if (i == -1) return;

	/*2. Находим максимальное значение j такое, что
	i < j <= n и P[i] < P[j].*/
	int j = -1;
	for (int a = n - 1; a > i; a--) {
		if (P[i] < P[a]) {
			j = a;
			break;
		}
	}

	/*3. Меняем P[i] и P[j] местами.*/
	swap(P[i], P[j]);

	/*4. Упорядочиваем по возрастанию «хвост» – элементы
	с i + 1 по n. (Инвертируем порядок).*/
	for (int a = i + 1, b = n - 1; a < b; a++, b--)
		swap(P[a], P[b]);
}

int Factorial(int n) {
	if (n == 1)
		return 1;
	return n * Factorial(n - 1);
}