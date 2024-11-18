#include <iostream>
#include <vector>
#include "Pyramid.h"

using std::cout;
using std::swap;

std::vector<int> CreateMassive(const int amount) {
	std::vector<int> a;
	for(int i = 0; i < amount; i++)
		a.push_back(rand() % (100 - 1 + 1) + 1);
	return a;
}

void PrintArray(const std::vector<int>& mas) {
	for (int i = 0; i < mas.size(); i++)
		cout << mas[i] << " ";
}

bool IsOrderly(const std::vector<int>& mas) {
	for (int i = 0; i < mas.size() - 1; i++) 
		if (mas[i] > mas[i + 1])
			return false;

	return true;
}


void PyramidSorting(std::vector<int>& mas) {

	for(int i = mas.size() / 2 - 1; i >= 0 ; i--)
		Sift2(mas, mas.size(), i);

	for (int i = mas.size() - 1; i > 0; i--) {
		swap(mas[0], mas[i]);
		Sift2(mas, i, 0);
	}

}
void Sift1(std::vector<int>& mas, const int size, int index) {
	int j = 2 * index + 1;

	while (j < size) {
		if ((j + 1) < size && mas[j + 1] > mas[j])
				j = j + 1;

		if (mas[j] > mas[index]) {
			swap(mas[j], mas[index]);
			index = j;
			j = 2 * index + 1;
		}
		else break;

	}
}
void Sift2(std::vector<int>& mas, const int size, int index) {
	int j = 2 * index + 1;
	int x = mas[index];
	bool f = 1;
	
	while (j < size) {
		if ((j + 1) < size && mas[j + 1] > mas[j])
			j = j + 1;

		if (mas[j] > mas[index]) {
			swap(mas[j], mas[index]);
			index = j;
			j = 2 * index + 1;
		}
		else {
			mas[index] = x;
			f = 0;
			break;
		}
	}
	if (f) mas[index] = x;
}