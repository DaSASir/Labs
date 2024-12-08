#include <iostream>
#include <vector>
#include <time.h>
#include "Radix.h"

int main() {
    setlocale(LC_ALL, "ru");
    //1. [10 баллов] Требуется реализовать алгоритм побитовой (не путать с поразрядной) сортировки массива. 
    // Также, для проверки работы алгоритма требуется написать функцию проверки отсортированного массива на упорядоченность. Достаточно сортировки неотрицательных чисел.
    srand((unsigned int)time(0));
    std::vector<int> ms = CreateMassive(10, 100, -100);

    std::cout << "Первоначальный массив: \n";
    Print(ms);

    BitSorting(ms);

    std::cout << std::endl << ((IsOrderly(ms)) ? "Массив отсортирован" : "Массив НЕ отсортирован") << std::endl;
  
    std::cout << "\nОтсортированный массив:\n";
    Print(ms);
    std::cout << std::endl;

    //2
    for (int i = 10; i <= 1000000; i *= 10) {
        time_t start, stop;
        double time = 0;
        for (int j = 0; j < 10000; j++) {
            std::vector<int> vec = CreateMassive(10, 100 * i, -100 * i);

            start = clock();

            BitSorting(vec);

            if (!IsOrderly(vec)) std::cout << "ИМЕЕТСЯ НЕОТСОРТИРОВАННЫЙ МАССИВ!!!";

            stop = clock();
            time += (double)(stop - start) / CLOCKS_PER_SEC;
        }

        std::cout << "Среднее время размерности " << i << " - " << time << std::endl;

    }


    return 0;
}