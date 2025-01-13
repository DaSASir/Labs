#include <iostream>
#include "Matrix.h"

int main() {
	setlocale(LC_ALL, "ru");

	BoolMatrix m1;
	BoolMatrix m2(8,8);
	BoolMatrix m3(8,8,1);
	BoolMatrix m4;
	BoolMatrix m5;

	m3.Print();


	return 0;
}