#include <iostream>
#include <vector>
#include "Radix.h"

using std::cout;

std::vector<int> CreateMassive(const int amount, const int max, const int min) {
	std::vector<int> a;
	for (int i = 0; i < amount; i++)
		a.push_back(rand() % (max - min + 1) + min);
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

void BitSorting(std::vector<int>& mas, const int max_element) {
	int left = 0;
	int right = mas.size() - 1;
	SymbolicSorting(mas, left, right);

	
}

void SymbolicSorting(std::vector<int>& mas, int& l, int& r) {
	l = 0;
	r = mas.size() - 1;
	int pivot = 0;

	while (l <= r) {
		while (mas[l] < pivot)
			l++;
		while (mas[r] > pivot)
			r--;

		if (l <= r) {
			std::swap(mas[l], mas[r]);
			l++;
			r--;
		}
	}
}


