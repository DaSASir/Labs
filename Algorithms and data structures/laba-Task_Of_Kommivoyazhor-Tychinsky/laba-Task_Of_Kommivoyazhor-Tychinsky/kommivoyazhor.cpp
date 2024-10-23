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
	std::cout << std::endl << "������� ��������� �����: ";
	std::cin >> entry_city;
	while (entry_city < 1 || entry_city > gauge) {
		std::cout << "������� ��� ��� ��������� �����: ";
		std::cin >> entry_city;
	}return entry_city;
}

//������� ��� �����
void AlgorithmDijkstra(int* P, const int n) {
	/*1. ������� ������������ �������� i �����, ���
	0 < i < n � P[i] < P[i+1]. ���� ������ i ��
	����������, �� ������� �������� � ���������
	������������ ���, ����� �.2.*/
	int i = -1;
	for (int a = n - 2; a > 0; a--) {
		if (P[a] < P[a + 1]) {
			i = a;
			break;
		}
	}

	if (i == -1) return;

	/*2. ������� ������������ �������� j �����, ���
	i < j <= n � P[i] < P[j].*/
	int j = -1;
	for (int a = n - 1; a > i; a--) {
		if (P[i] < P[a]) {
			j = a;
			break;
		}
	}

	/*3. ������ P[i] � P[j] �������.*/
	std::swap(P[i], P[j]);

	/*4. ������������� �� ����������� ������ � ��������
	� i + 1 �� n. (����������� �������).*/
	for (int a = i + 1, b = n - 1; a < b; a++, b--)
		std::swap(P[a], P[b]);
}

//����� ������ ���������� ������������ ����
int* FindMinimumPathWeight(int** matrix, const int gauge, const int entry_city, int& min_weight) {
	int amount_of_path = 1;//������� ���������� �����
	for (int i = 1; i <= gauge - 1; i++)
		amount_of_path *= i;

	int* min_path = new int[gauge + 1];//����������� ����
	int* this_path = new int[gauge + 1];//�������� ������� ���� � �������
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

//���������
int* HeuristicAlgorithm1(const int gauge, int** matrix, int& min_path, const int entry_city) {
	/*����: �������� ��������� ���� ����������� ��������� �� ������� �������*/
	int** path_e = new int*[gauge];//������� ���������

	min_path = 0;//������� ���� ����

	int index_col = entry_city - 1;//������ ������ ��������
	
	for (int step = 0; step < gauge; step++) {//���� �������
		path_e[step] = new int[2];//������� ������� �� ������ 1 � ������ 2

		int index_row = -1;//������� ��������

		int min_element = -1; //������� ����������� �������
		for (int i = 0; i < gauge; i++) {

			if (i == entry_city - 1 && step != gauge - 1) i++; //���� ������ ������������ �������� ������ ��� ��������� �����, �� ������� ��� �� ��������

			if ((matrix[index_col][i] < min_element || min_element == -1) && matrix[index_col][i] != 0) {
				min_element = matrix[index_col][i];//���������� �������� 
				index_row = i;//���������� ������� ��������
			}
		}

		for (int j = 0; j < gauge; j++) {//�������� ������ � �������
			matrix[index_col][j] = 0;
			matrix[j][index_row] = 0;
		}

		path_e[step][0] = index_col + 1;//������ �������� � ������� 
		path_e[step][1] = index_row + 1;

		min_path += min_element;//��� ������ ����

		index_col = index_row;//��������� ��������� ����� = ������ ���������� 

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
