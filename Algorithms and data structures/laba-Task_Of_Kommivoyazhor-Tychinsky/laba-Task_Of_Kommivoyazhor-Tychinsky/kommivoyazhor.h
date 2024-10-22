#pragma once
#pragma once

void CreateMatrixCities(int** matrix, const int gauge, const int max_number, const int min_number);
void DeleteMatrixCities(int** matrix, const int gauge);

void Print(int** matrix, const int gauge);
int CreateEntryCity(int gauge);

int** CreatePathMatrix(int gauge, int entry_city, int amount_of_path);
void AlgorithmDijkstra(int* P, int n);
int Factorial(int n);


