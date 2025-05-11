#include <iostream>
#include "Plenty.h"

int main() {
	setlocale(LC_ALL, "ru");

	char* array = new char[3];
	array[0] = 'w';
	array[1] = 'a';
	array[1] = 'a';
	array[2] = '\0';
	


	Plenty set(array);

	set |= ~set;
	std::cout << set;


	return 0;
}
