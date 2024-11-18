#include <iostream>
#include <vector>
#include <time.h>
#include "Pyramid.h"

int main() {
    setlocale(LC_ALL, "ru");
    //1. [10 баллов] Требуется реализовать алгоритм пирамидальной сортировки массива.
    //  Также, для проверки работы алгоритма требуется написать функцию проверки отсортированного массива на упорядоченность.
    srand((unsigned int)time(0));
    std::vector<int> ms = CreateMassive(10);

    std::cout << "Первоначальный массив: \n";
    PrintArray(ms);


    PyramidSorting(ms);
    //PyramidSorting(ms);


    std::cout << "\nИзмененный массив: \n";
    PrintArray(ms);

    std::cout << "\n\n";

    //2. [10 баллов] Используя тестовые массивы, сгенерированные для лабораторной № 4,
    //  совершить хотя бы три запуска алгоритма на каждом тестовом массиве и вычислить среднее время работы алгоритма для каждого из массивов
    //  (экономьте своё время, реализовав вызов сортировок с помощью циклов, а не перезапуском программы или дублированием кода).
    //  Полученные данные в виде отчёта также приложите к ответу.

    for (int i = 10; i <= 1000000; i *= 10) {
        time_t start, stop;
        double time = 0;
        for (int j = 0; j < 3; j++) {
            std::vector<int> vec = CreateMassive(i);

            start = clock();

            while(!IsOrderly(vec)) PyramidSorting(vec);

            stop = clock();
            time += (double)(stop - start) / CLOCKS_PER_SEC;
        }

        std::cout << "Среднее время размерности " << i << " - " << time << std::endl;
        
    }

}