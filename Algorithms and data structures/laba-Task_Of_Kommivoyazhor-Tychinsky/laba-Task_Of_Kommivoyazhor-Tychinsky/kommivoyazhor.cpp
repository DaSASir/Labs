#include <iostream>
#include <time.h>
#include <vector>
#include "kommivoyazhor.h"

using std::cout;
using std::cin;

std::vector<std::vector<int>> CreateMatrixCities(const int gauge, const int max_number, const int min_number) {
	std::vector<std::vector<int>> matrix(gauge, std::vector<int>(gauge, 0));
	for (int i = 0; i < gauge; i++)
		for (int j = 0; j < gauge; j++) 
			if (i != j)
				matrix[i][j] = (rand() % (max_number - min_number + 1) + min_number);

	return matrix;
}

void Print(std::vector<std::vector<int>>& matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.size(); j++)
			cout << matrix[i][j] << " ";
		cout << "\n";
	}
}

int CreateEntryCity(const int gauge) {
	int entry_city;
	cout << "\nВведите начальный город: ";
	cin >> entry_city;
	while (entry_city < 1 || entry_city > gauge) {
		cout << "Введите еще раз начальный город: ";
		cin >> entry_city;
	}return entry_city;
}

//функции для путей
void AlgorithmDijkstra(std::vector<int>& P, const int n) {
	using std::swap;
	/*1. Находим максимальное значение i такое, что
	0 < i < n и P[i] < P[i+1]. Если такого i не
	существует, то процесс завершен – следующей
	перестановки нет, иначе п.2.*/
	int i = -1;
	for (int a = n - 2; a > 0; a--) 
		if (P[a] < P[a + 1]) {
			i = a;
			break;
		}

	if (i == -1) return;

	/*2. Находим максимальное значение j такое, что
	i < j <= n и P[i] < P[j].*/
	int j = -1;
	for (int a = n - 1; a > i; a--) 
		if (P[i] < P[a]) {
			j = a;
			break;
		}

	/*3. Меняем P[i] и P[j] местами.*/
	swap(P[i], P[j]);

	/*4. Упорядочиваем по возрастанию «хвост» – элементы
	с i + 1 по n. (Инвертируем порядок).*/
	for (int a = i + 1, b = n - 1; a < b; a++, b--)
		swap(P[a], P[b]);
}

std::vector<int> FindMinimumPathWeight(std::vector<std::vector<int>>& matrix, const int gauge, const int entry_city, int& min_weight) {
	int amount_of_path = 1;//кол-во перестановок
	for (int i = 1; i <= gauge - 1; i++)
		amount_of_path *= i;

	std::vector<int> path(gauge + 1, 0);

	path[0] = entry_city;//1-й маршрут
	for (int index = 1, city = 1; index < gauge; index++, city++) {
		if (city == entry_city && city < gauge) city++;
		path[index] = city;
	}
	path[gauge] = entry_city;

	min_weight = INT16_MAX;
	std::vector<int> min_path;

	for (int step = 0; step < amount_of_path; step++) {
		int weight = 0;

		for (int i = 0; i < gauge; i++)
			weight += matrix[path[i] - 1][path[i + 1] - 1];
		
		if (weight < min_weight) {
			min_weight = weight;
			min_path = path;
		}

		AlgorithmDijkstra(path, gauge);
	}

	return min_path;
}

//эвристика
std::vector<int> HeuristicAlgorithm1(const int gauge, std::vector<std::vector<int>>& matrix, int& min_path, const int entry_city) {
	/*Идея: Выбираем исходящую дугу минимальной стоимости из текущей вершины*/
	std::vector<std::vector<int>>plan_of_path(gauge, std::vector<int>(2,0));
	std::vector<bool> visited(gauge, 0);

	int prev_city = (entry_city - 1),
		next_city = -1;

	min_path = 0;

	for (int step = 0; step < gauge - 1; step++) {
		int weight = INT16_MAX;

		for (int index = 0; index < gauge; index++) 
			if (!visited[index] && matrix[prev_city][index] != 0 && matrix[prev_city][index] < weight) {
				next_city = index;
				weight = matrix[prev_city][index];
			}

		if (next_city != -1) {
			visited[prev_city] = 1;

			plan_of_path[step][0] = prev_city + 1;
			plan_of_path[step][1] = next_city + 1;

			min_path += weight;
			prev_city = next_city;
		}
	}

	min_path += matrix[prev_city][entry_city - 1];
	plan_of_path[gauge - 1][0] = prev_city + 1;
	plan_of_path[gauge - 1][1] = entry_city;

	return ConstructorHeuristicPath(plan_of_path, entry_city, gauge);
}
std::vector<int> ConstructorHeuristicPath(std::vector<std::vector<int>>& path, const int entry_city, const int gauge) {
	std::vector<int> e_path(gauge + 1, 0);

	e_path[0] = entry_city;
	for (int i = 0; i < gauge; i++) 
		for (int j = 0; j < gauge; j++) 
			if (path[j][0] == (e_path[i])) {
				e_path[i + 1] = path[j][1];
				break;
			}

	return e_path;
}
