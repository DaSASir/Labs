#include <iostream>
#include <vector>
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


    std::cout << "\nИзмененный массив: \n";
    PrintArray(ms);

    std::cout << "\n";
}