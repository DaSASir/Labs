#pragma once

void Create_Matrix_of_cities(int** matrix, const int gauge, const int max_number, const int min_number);
void Delete_Matrix_of_cities(int** matrix, const int gauge);

void Print(int** matrix, const int gauge);

void Create_Path(int* Path, int gauge, int entry_city);

int MinFare(int** matrix, int* Path, int gauge, int entry_city); #pragma once
