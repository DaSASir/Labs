#include <iostream>
#include <vector>
#include "Haora.h"

using std::cout;

std::vector<int> CreateMassive(const int amount) {
	std::vector<int> a;
	for (int i = 0; i < amount; i++)
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


void HoaraSorting(std::vector<int>& mas,const int left,const int right) {
	if (left >= right) return;

	int l = left, r = right;
	int pivot = mas[(left + right) / 2];

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
	HoaraSorting(mas, left, r);
	HoaraSorting(mas, l, right);
}