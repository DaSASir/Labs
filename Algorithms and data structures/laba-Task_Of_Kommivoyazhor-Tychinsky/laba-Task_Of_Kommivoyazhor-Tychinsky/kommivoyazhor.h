#pragma once

//������� ��������� �������
int** CreateMatrixCities(const int gauge, const int max_number, const int min_number);
void DeleteMatrix(int** matrix, const int gauge);

void Print(int** matrix, const int gauge);

//������� �����
int CreateEntryCity(const int gauge);

int** CreatePathMatrix(const int gauge, const int entry_city);
void AlgorithmDijkstra(int* P, const int n);

int Factorial(const int n);

void PrintPath(int** path, const int gauge);

//���������� ������������ ����
int MinimumPathWeight(int** matrix, int** path,const int gauge, int& index);

//���������
//int* HeuristicAlgorithm(const int gauge, int** matrix, int& min_path, int entry_city);
int* HeuristicAlgorithm1(const int gauge, int** matrix, int& min_path, const int entry_city);
int* ConstructorHeuristicPath(int** path, const int entry_city, const int gauge);