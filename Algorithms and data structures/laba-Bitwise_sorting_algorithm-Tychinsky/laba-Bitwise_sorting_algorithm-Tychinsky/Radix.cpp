#include <iostream>
#include <vector>
#include <assert.h>
#include "Radix.h"

using std::cout;
using std::swap;

std::vector<int> CreateMassive(const int amount, const int max, const int min) {
	std::vector<int> a;
	for (int i = 0; i < amount; i++)
		a.push_back(rand() % (max - min + 1) + min);
	return a;
}

void Print(const std::vector<int>& mas) {
	for(int i : mas) cout << i << " ";
}

bool IsOrderly(const std::vector<int>& mas) {
	for (int i = 0; i < mas.size() - 1; i++)
		if (mas[i] > mas[i + 1])
			return false;

	return true;
}

void BitSorting(std::vector<int>& mas) {
	assert(mas.size() > 1);

	int l = 0,
		r = mas.size() - 1;

	while (l <= r) {
		while (mas[l] < 0 && l <= r) l++;

		while (mas[r] >= 0 && r >= l) r--;

		if (l <= r) {
			swap(mas[l], mas[r]);
			l++;
			r--;
		}
	}

	int mask = 1 << 31;
	SortingPositive(mas, l, (mas.size() - 1), mask);
}

void SortingPositive(std::vector<int>& mas,
	const int left, const int right, const int mask) {

	assert(left < right && mask > 0);

	int l = left,
		r = right;

	while (l <= r) {
		while ((mas[l] & mask) == 0 && l <= r) l++;

		while ((mas[l] & mask) == 1 && l <= r) r--;

		if (l <= r) {
			swap(mas[l], mas[r]);
			l++;
			r--;
		}
	}

	SortingPositive(mas, left, r, mask >> 1);
	SortingPositive(mas, l, right, mask >> 1);
}