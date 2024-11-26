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

void BitSorting(std::vector<int>& mas) {
	int left = 0;
	int right = mas.size() - 1;
	SymbolicSorting(mas, left, right);

	MinusSorting(mas, 0, right - 1, 1);
	PlusSorting(mas, left - 1, 0, 1);
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

void MinusSorting(std::vector<int>& mas, const int left, const int right, int mask) {
	int l = left, r = right;
	while (l <= r) {
		while ((mas[l] & mask) == mask)
			l++;
		while ((mas[r] & mask) != mask)
			r--;

		if (l <= r) {
			std::swap(mas[l], mas[r]);
			l++;
			r--;
		}
	}
	MinusSorting(mas, left, r, mask <<= 1);
	MinusSorting(mas, l, right, mask <<= 1);
}
void PlusSorting(std::vector<int>& mas, const int left, const int right, int mask) {
	int l = left, r = right;
	while (l <= r) {
		while ((mas[l] & mask) != mask)
			l++;
		while ((mas[r] & mask) == mask)
			r--;

		if (l <= r) {
			std::swap(mas[l], mas[r]);
			l++;
			r--;
		}
	}
	PlusSorting(mas, left, r, mask <<= 1);
	PlusSorting(mas, l, right, mask <<= 1);
}
