#include <iostream>
#include <time.h>
#include "kommivoyazhor.h"

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
			std::cout << matrix[i][j] << " ";
		std::cout << std::endl;
	}
}
int CreateEntryCity(const int gauge) {
	int entry_city;
	std::cout << std::endl << "Введите начальный город: ";
	std::cin >> entry_city;
	while (entry_city < 1 || entry_city > gauge) {
		std::cout << "Введите еще раз начальный город: ";
		std::cin >> entry_city;
	}return entry_city;
}

//функции для путей
void AlgorithmDijkstra(int* P, const int n) {
	/*1. Находим максимальное значение i такое, что
	0 < i < n и P[i] < P[i+1]. Если такого i не
	существует, то процесс завершен – следующей
	перестановки нет, иначе п.2.*/
	int i = -1;
	for (int a = n - 2; a > 0; a--) {
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
	std::swap(P[i], P[j]);

	/*4. Упорядочиваем по возрастанию «хвост» – элементы
	с i + 1 по n. (Инвертируем порядок).*/
	for (int a = i + 1, b = n - 1; a < b; a++, b--)
		std::swap(P[a], P[b]);
}

//новый способ нахождения минимального пути
int* FindMinimumPathWeight(int** matrix, const int gauge, const int entry_city, int& min_weight) {
	int amount_of_path = 1;//создаем количество путей
	for (int i = 1; i <= gauge - 1; i++)
		amount_of_path *= i;

	int* min_path = new int[gauge + 1];//минимальный путь
	int* this_path = new int[gauge + 1];//проверка данного пути с прошлым
	int* past_path = new int[gauge + 1];

	int cheese = 1;
	for (int i = 0; i < gauge + 1; i++) {
		if (i == 0 || i == gauge)
			min_path[i] = entry_city;
		else {
			if (cheese != entry_city && cheese <= gauge) {
				min_path[i] = cheese;
				cheese++;
			}
			else {
				cheese++;
				min_path[i] = cheese;
				cheese++;
			}
		}
		this_path[i] = min_path[i];
		past_path[i] = min_path[i];
	}


	int weight_past_path = 0;

	for (int j = 0; j < gauge; j++)
		weight_past_path += matrix[past_path[j] - 1][past_path[j + 1] - 1];

	min_weight = weight_past_path;

	for (int step = 0; step < amount_of_path; step++) {
		for (int j = 0; j <= gauge; j++)
			past_path[j] = this_path[j];

		AlgorithmDijkstra(this_path, gauge);

		int weight_this_path = 0;

		for (int j = 0; j < gauge; j++)
			weight_this_path += matrix[this_path[j] - 1][this_path[j + 1] - 1];

		if (weight_this_path < weight_past_path) {
			min_weight = weight_this_path;
			for (int j = 0; j <= gauge; j++)
				min_path[j] = this_path[j];
		}
			

	}
	delete[] this_path, past_path;
	return min_path;
}

//эвристика
int* HeuristicAlgorithm1(const int gauge, int** matrix, int& min_path, const int entry_city) {
	/*Идея: Выбираем исходящую дугу минимальной стоимости из текущей вершины*/
	int** path_e = new int*[gauge];//матрица переходов

	min_path = 0;//счетчик веса пути

	int index_col = entry_city - 1;//строка поиска элемента
	
	for (int step = 0; step < gauge; step++) {//шаги решения
		path_e[step] = new int[2];//создаем переход от города 1 к городу 2

		int index_row = -1;//столбец элемента

		int min_element = -1; //создаем минимальный элемент
		for (int i = 0; i < gauge; i++) {

			if (i == entry_city - 1 && step != gauge - 1) i++; //если индекс минимального значения примет наш начальный город, но матрица еще не обнулена

			if ((matrix[index_col][i] < min_element || min_element == -1) && matrix[index_col][i] != 0) {
				min_element = matrix[index_col][i];//нахождение элемента 
				index_row = i;//нахождение столбца элемента
			}
		}

		for (int j = 0; j < gauge; j++) {//обнуляем строку и столбец
			matrix[index_col][j] = 0;
			matrix[j][index_row] = 0;
		}

		path_e[step][0] = index_col + 1;//вносим значения в матрицу 
		path_e[step][1] = index_row + 1;

		min_path += min_element;//вес нашего пути

		index_col = index_row;//следующий начальный город = нашему последнему 

	}

	return ConstructorHeuristicPath(path_e, entry_city, gauge);
}
int* ConstructorHeuristicPath(int** path, const int entry_city, const int gauge) {
	int* e_path = new int[gauge + 1];

	e_path[0] = entry_city;

	for (int i = 0; i < gauge; i++) {
		for (int j = 0; j < gauge; j++) {
			if (path[j][0] == e_path[i]) {
				e_path[i + 1] = path[i][1];
				break;
			}
		}
	}

	return e_path;
}
