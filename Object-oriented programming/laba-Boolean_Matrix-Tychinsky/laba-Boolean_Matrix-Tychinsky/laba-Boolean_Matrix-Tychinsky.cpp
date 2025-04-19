#include <iostream>
#include "Matrix.h"

#include <array>

int main() {
	setlocale(LC_ALL, "ru");

	//std::array<std::array<char, 8>, 8> mat2;
	//mat2.size();

	constexpr int n = 4;
	constexpr int m = 2;
	char mat[n][m];
	char* rows[n];
	for (int i = 0; i < n; i++) {
		rows[i] = &mat[i][0];
		for (int j = 0; j < m; j++)
			mat[i][j] = '1';
	}

	BoolMatrix m1;
	BoolMatrix m2(m, n, 1);
	BoolMatrix m3(&rows[0], m, n);
	BoolMatrix m4(m2);


	std::cout << "-----\n";
	m3 &= m2;
	std::cout << "-----\n";

	m2.Print();
	m3.Print();
	std::cout << "Weight: " << m3.Weight() << std::endl;

	return 0;
}