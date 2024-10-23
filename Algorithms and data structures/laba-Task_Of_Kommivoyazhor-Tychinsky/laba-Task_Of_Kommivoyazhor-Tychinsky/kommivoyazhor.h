#pragma once

//матрица стоимости городов
int** CreateMatrixCities(const int gauge, const int max_number, const int min_number);
void DeleteMatrix(int** matrix, const int gauge);

void Print(int** matrix, const int gauge);

int CreateEntryCity(const int gauge);

//нахождение минимального пути
int* FindMinimumPathWeight(int** matrix, const int gauge, const int entry_city, int& min_weight);

//эвристика
int* HeuristicAlgorithm1(const int gauge, int** matrix, int& min_path, const int entry_city);
int* ConstructorHeuristicPath(int** path, const int entry_city, const int gauge);