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
int CreateEntryCity(const int gauge) {
	int entry_city;
	cout << endl << "������� ��������� �����: ";
	cin >> entry_city;
	while (entry_city < 1 || entry_city > gauge) {
		cout << "������� ��� ��� ��������� �����: ";
		cin >> entry_city;
	}return entry_city;
}

//������� ��� �����
int** CreatePathMatrix(const int gauge, const int entry_city) {
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

void AlgorithmDijkstra(int* P, const int n) {
	/*1. ������� ������������ �������� i �����, ���
	0 < i < n � P[i] < P[i+1]. ���� ������ i ��
	����������, �� ������� �������� � ���������
	������������ ���, ����� �.2.*/
	int i = -1;
	for (int a = n - 2; a >= 0; a--) {
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
	swap(P[i], P[j]);

	/*4. ������������� �� ����������� ������ � ��������
	� i + 1 �� n. (����������� �������).*/
	for (int a = i + 1, b = n - 1; a < b; a++, b--)
		swap(P[a], P[b]);
}

int Factorial(const int n) {
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


//���������� ������������ ����
int MinimumPathWeight(int** matrix, int** path, const int gauge, int& index) {
	int min_path = -1;

	for (int i = 0; i < Factorial(gauge - 1); i++) {
		int this_path = 0;

		for (int j = 0; j < gauge; j++) 
			this_path += matrix[path[i][j] - 1][path[i][j + 1] - 1];
		
		if (min_path > this_path || min_path == -1) {
			min_path = this_path;
			index = i;
		}
	}
	return min_path;
}

//���������
/*
int* HeuristicAlgorithm(int gauge, int** matrix, int& min_path, int entry_city) {
	min_path = 0;//����������� ��� ����

	int* sum_elements = new int[gauge];//������ �����
	int** path = new int* [gauge];//������� ����� 

	for (int i = 0; i < gauge; i++) {//���� �������

		path[i] = new int[2];//������� ���� �� ������1 � ������2

		int min_number = -1;//����������� ����� � ������
		int col_of_element = -1;//������������ ������
		int row_of_element = -1;//������� ������������ ����� � ������������ ������

		for (int k = 0; k < gauge; k++) {// ���������� ����
			sum_elements[k] = 0;
			for (int j = 0; j < gauge; j++)
				sum_elements[k] += matrix[k][j];
		}
			
		int max_sum = sum_elements[0];
		col_of_element = 0;
		for (int j = 1; j < gauge; j++) {//������� ������������ ����
			if (sum_elements[j] > max_sum) {
				max_sum = sum_elements[j];
				col_of_element = j;//������� ����� ������� ������
			}
		}

		for (int j = 0; j < gauge; j++)
			if ((min_number > matrix[col_of_element][j] || min_number == -1) && matrix[col_of_element][j] != 0) {
				min_number = matrix[col_of_element][j];//������ ����������� ������� 
				row_of_element = j;//������� ������� ������������ ��������
			}

		min_path += min_number;//������� ����������� ����

		for (int j = 0; j < gauge; j++) {//�������� ������ � �������
			matrix[col_of_element][j] = 0;
			matrix[j][row_of_element] = 0;
		}
		
		path[i][0] = col_of_element + 1;//������ � ������� ����� 
		path[i][1] = row_of_element + 1;
	}
	
	delete[] sum_elements;
	return ConstructorHeuristicPath(path, entry_city, gauge);
}
*/
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
		
	DeleteMatrix(path, gauge);

	return e_path;
}
