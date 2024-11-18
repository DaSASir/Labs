#include <iostream>
#include <vector>
#include "Pyramid.h"

using std::cout;
using std::swap;

std::vector<int> CreateMassive(int amount) {
	std::vector<int> a;
	for(int i = 0; i < amount; i++)
		a.push_back(rand() % (100 - 1 + 1) + 1);
	return a;
}

void PrintArray(std::vector<int> mas) {
	for (int i = 0; i < mas.size(); i++)
		cout << mas[i] << " ";
}

bool IsOrderly(std::vector<int> mas) {
	for (int i = 0; i < mas.size() - 1; i++) 
		if (mas[i] > mas[i + 1])
			return false;

	return true;
}


void PyramidSorting(std::vector<int>& mas) {
	Sift1(mas, mas.size(), 0);
}
void Sift1(std::vector<int> mas, int size, int index) {
	int j = 2 * index + 1;

	while (index < size) {

		if (j < size) {
			if ((j + 1) < size)
				if (mas[j + 1] > mas[j])
					j = j + 1;

			if (mas[j] > mas[index]) {
				swap(mas[index], mas[j]);
				index = j;
				j = 2 * index + 1;
			}
			else break;
			
		}
		else break;

	}
}