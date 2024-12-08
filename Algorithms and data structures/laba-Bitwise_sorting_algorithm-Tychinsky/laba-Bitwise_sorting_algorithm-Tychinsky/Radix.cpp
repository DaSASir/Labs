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
	cout << std::endl;
}

bool IsOrderly(const std::vector<int>& mas) {
	for (int i = 0; i < mas.size() - 1; i++)
		if (mas[i] > mas[i + 1])
			return false;

	return true;
}

void BitSorting(std::vector<int>& mas) {
	assert(mas.size() > 1);

	int min_num = GetMin(mas),
		size = mas.size();

	if (min_num < 0)
		for (int i = 0; i < size; i++)
			mas[i] -= min_num;

	int max_num = GetMax(mas);

	for (int bit = 0; (1 << bit) <= max_num; bit++) {
		std::vector<int> array_0, array_1;

		for (int i = 0; i < size; i++) {
			if (mas[i] & (1 << bit))
				array_1.push_back(mas[i]);
			else
				array_0.push_back(mas[i]);
		}

		int index = 0;
		for (int i = 0; i < array_0.size(); i++) {
			mas[index] = array_0[i];
			index++;
		}
		for (int i = 0; i < array_1.size(); i++) {
			mas[index] = array_1[i];
			index++;
		}
	}

	if (min_num < 0)
		for (int i = 0; i < size; i++)
			mas[i] += min_num;
}

int GetMax(const std::vector<int>& mas) {
	int x = mas[0];
	for (int i = 1; i < mas.size(); i ++)
		if (x < mas[i])
			x = mas[i];
	return x;
}
int GetMin(const std::vector<int>& mas) {
	int x = mas[0];
	for (int i = 1; i < mas.size(); i++)
		if (x > mas[i])
			x = mas[i];
	return x;
}
