﻿#include <iostream>
#include <vector>
#include "Radix.h"

int main() {
    setlocale(LC_ALL, "ru");
    //1. [10 баллов] Требуется реализовать алгоритм побитовой (не путать с поразрядной) сортировки массива. 
    // Также, для проверки работы алгоритма требуется написать функцию проверки отсортированного массива на упорядоченность. Достаточно сортировки неотрицательных чисел.
    srand((unsigned int)time(0));
    std::vector<int> ms = CreateMassive(10, 100, -100);

    std::cout << "Первоначальный массив: \n";
    PrintArray(ms);

    BitSorting(ms, 100);
    std::cout << "\nОтсортированный массив:\n";
    PrintArray(ms);


}