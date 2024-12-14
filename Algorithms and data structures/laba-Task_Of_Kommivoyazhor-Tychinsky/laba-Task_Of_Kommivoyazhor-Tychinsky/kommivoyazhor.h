#pragma once

//матрица стоимости городов
std::vector<std::vector<int>> CreateMatrixCities(const int gauge, const int max_number, const int min_number);

void Print(std::vector<std::vector<int>>& matrix);

int CreateEntryCity(const int gauge);

//нахождение минимального пути
std::vector<int> FindMinimumPathWeight(std::vector<std::vector<int>>& matrix, const int gauge, const int entry_city, int& min_weight);

//эвристика
std::vector<int> HeuristicAlgorithm1(const int gauge, std::vector<std::vector<int>>& matrix, int& min_path, const int entry_city);
std::vector<int> ConstructorHeuristicPath(std::vector<std::vector<int>>& path, const int entry_city, const int gauge);