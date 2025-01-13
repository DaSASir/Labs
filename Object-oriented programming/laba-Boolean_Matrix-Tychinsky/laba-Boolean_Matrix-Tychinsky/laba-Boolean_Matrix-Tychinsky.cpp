#include <iostream>
#include "Matrix.h"

int main() {
	setlocale(LC_ALL, "ru");

	char** mat = new char*[8];
	for (int i = 0; i < 8; i++) {
		mat[i] = new char[8];
		for (int j = 0; j < 8; j++)
			mat[i][j] = '1';
	}

	BoolMatrix m1;
	BoolMatrix m2(8, 8, 1);
	BoolMatrix m3(mat, 8, 8);
	BoolMatrix m4(m2);

	//std::cout << m1  << "\n" << m2  << "\n" << m3 << "\n" << m4 << "\n";

	m3.Inversion(3, 3, 7);
	m3.Print();
	std::cout << m3[3];

	return 0;
}