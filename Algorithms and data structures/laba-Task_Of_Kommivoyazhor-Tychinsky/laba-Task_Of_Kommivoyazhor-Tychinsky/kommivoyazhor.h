#pragma once

//������� ��������� �������
int** CreateMatrixCities(const int gauge, const int max_number, const int min_number);
void DeleteMatrix(int** matrix, const int gauge);

void Print(int** matrix, const int gauge);

//������� �����
int CreateEntryCity(int gauge);

int** CreatePathMatrix(int gauge, int entry_city);
void AlgorithmDijkstra(int* P, int n);

int Factorial(int n);

void PrintPath(int** path, const int gauge);

//���������� ������������ ����
int MinimumPathWeight(int** matrix, int** path,const int gauge, int& index);

