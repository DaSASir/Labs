#include <iostream>
#include <time.h>
#include "kommivoyazhor.h"

using namespace std;

void Create_Matrix_of_cities(int** matrix, const int gauge, const int max_number, const int min_number) {
	srand((unsigned int)time(0));
	for (int i = 0; i < gauge; i++)
		matrix[i] = new int[gauge];

	for (int i = 0; i < gauge; i++)
		for (int j = 0; j < gauge; j++) {
			if (i == j)
				matrix[i][j] = 0;
			else
				matrix[i][j] = rand() % (max_number - min_number + 1) + min_number;
		}
}
void Delete_Matrix_of_cities(int** matrix, const int gauge) {
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
void Create_Path(int* Path, int gauge, int entry_city) {
	Path[0] = entry_city;
	Path[gauge] = entry_city;
	for (int i = 1; i < gauge; i++) {
		if (i == entry_city)
			i++;
		Path[i] = i;
	}
}
int MinFare(int** matrix, int* Path, int gauge, int entry_city) {
	Create_Path(Path, gauge, entry_city);
	int min_price = 0, current_min_price = 0;
	return 0;
}