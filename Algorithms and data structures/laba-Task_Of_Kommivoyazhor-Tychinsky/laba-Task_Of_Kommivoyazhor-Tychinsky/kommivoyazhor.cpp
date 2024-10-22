#include <iostream>
#include <time.h>
#include "kommivoyazhor.h"

using namespace std;

int** CreateMatrixCities(const int gauge, const int max_number, const int min_number) {
	int** matrix = new int* [gauge];
	for (int i = 0; i < gauge; i++)
		matrix[i] = new int[gauge];

	srand((unsigned int)time(0));

	for (int i = 0; i < gauge; i++)
		for (int j = 0; j < gauge; j++) {
			if (i == j)
				matrix[i][j] = 0;
			else
				matrix[i][j] = rand() % (max_number - min_number + 1) + min_number;
		}
	return matrix;
}
void DeleteMatrix(int** matrix, const int gauge) {
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
int** CreatePathMatrix(int gauge, int entry_city) {
	int amount_of_path = Factorial(gauge - 1);

	int** path = new int* [amount_of_path];
	for (int i = 0; i < amount_of_path; i++)
		path[i] = new int[gauge + 1];

	int cheese = 1;
	for (int i = 0; i < gauge + 1; i++) {
		if (i == 0 || i == gauge)
			path[0][i] = entry_city;
		else {
			if (cheese != entry_city && cheese <= gauge) {
				path[0][i] = cheese;
				cheese++;
			}
			else {
				cheese++;
				path[0][i] = cheese;
				cheese++;
			}
		}
	}
	
	for (int i = 1; i < amount_of_path; i++) {
		for (int j = 0; j <= gauge; j++)
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

void PrintPath(int** path, const int gauge) {
	for (int i = 0; i < Factorial(gauge-1); i++) {
		for (int j = 0; j <= gauge; j++)
			cout << path[i][j] << " ";
		cout << endl;
	}
}


//вычисление минимального пути
int MinimumPathWeight(int** matrix, int** path, const int gauge) {
	int min_path = -1;

	for (int i = 0; i < Factorial(gauge - 1); i++) {
		int this_path = 0;

		for (int j = 0; j < gauge; j++) 
			this_path += matrix[path[i][j] - 1][path[i][j + 1] - 1];
		
		if (min_path > this_path || min_path == -1)
			min_path = this_path;
	}
	return min_path;
}

