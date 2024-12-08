#include <iostream>
#include <vector>
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

    return 0;
}