#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
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

		HoaraSorting(mas, 0, mas.size() - 1);

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