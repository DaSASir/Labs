#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
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
	int l = 0,
		r = mas.size() - 1;

	while (l <= r) {
		while (l <= r && mas[l] < 0) l++;
		while (l <= r && mas[r] >= 0) r--;

		if (l <= r) {
			swap(mas[l], mas[r]);
			l++;
			r--;
		}
	}

	int mask = 1 << 30;
	Sorting(mas, 0, r, mask);
	Sorting(mas, l, (mas.size() - 1), mask);
}

void Sorting(std::vector<int>& mas,
	const int left, const int right, const int mask) {
	if (left >= right || mask <= 0) return;

	int l = left,
		r = right;

	while (l <= r) {
		while (l <= r && !(mask & mas[l])) l++;
		while (l <= r && (mask & mas[r])) r--;

		if (l <= r) {
			swap(mas[l], mas[r]);
			l++;
			r--;
		}
	}
	Sorting(mas, left, r, mask >> 1);
	Sorting(mas, l, right, mask >> 1);
}

double MiddleTimeOfFile() {
	std::ifstream f("C:\\GitHub_Repositories\\Labs\\Algorithms and data structures\\laba-Shell_sorting_algorithm-Tychinsky\\laba-Shell_sorting_algorithm-Tychinsky\\Arrays.txt");
	if (!f.is_open()) {
		perror("---File not open!---");
		exit(-1);
	}

	int size[] = { 10000 ,10000 ,10000 ,
				   100000 ,100000 ,100000 ,
				   1000000 ,1000000 ,1000000 };

	std::vector<double> average_time;

	for (int j = 0; j < 9; j++) {
		std::vector<int> mas;
		int element;

		for (int i = 0; i < size[j] && f >> element; i++)
			mas.push_back(element);

		if (mas.size() != size[j]) {
			perror("\nProblem in size!!!\n");
			exit(-1);
		}

		time_t start = clock();

		BitSorting(mas);

		time_t stop = clock();
		double time = static_cast<double>(stop - start) / CLOCKS_PER_SEC;

		if (!IsOrderly(mas))
			cout << "Массив не упорядочен!!!" << j << std::endl;
		else
			average_time.push_back(time);
	}

	cout << "Вывод времени каждого массива:\n";
	for (int i = 0; i < average_time.size(); i++) {
		if (i % 3 == 0 && i != 0)
			cout << "\n";

		cout << average_time[i] << "s ";

	}

	double total_time = 0.0;
	for (double t : average_time)
		total_time += t;

	f.close();
	return (total_time / average_time.size());
}