#include <iostream>
#include <vector>
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
	if (mas.size() <= 1) return;

	int left = 0,
		right = (unsigned)mas.size() - 1;

	while (left <= right) {
		while (mas[left] < 0 && left < (unsigned)mas.size())
			left++;
		while (mas[right] >= 0 && right >= 0)
			right--;

		if (left <= right) {
			swap(mas[left], mas[right]);
			left++;
			right--;
		}
	}

	int mask = 1 << 30;
	if(right >= 0) 
		Sorting(mas, 0, right, mask);
	if(left < mas.size()) 
		Sorting(mas, left, (unsigned)mas.size() - 1, mask);
}

void Sorting(std::vector<int>& mas,  int left,  int right, int mask) {
	if (left >= right || mask <= 0)
		return;

	int l = left,
		r = right;

	while (l <= r) {
		while ((mas[l] & mask) == 0 && l <= r)
			l++;
		while ((mas[r] & mask) != 0 && l<= r)
			r--;

		if (l <= r) {
			swap(mas[l], mas[r]);
			l++;
			r--;
		}
	}
	if (left <= r)
		Sorting(mas, left, r, mask >> 1);
	if (l <= right) 
		Sorting(mas, l, right, mask >> 1);
}
