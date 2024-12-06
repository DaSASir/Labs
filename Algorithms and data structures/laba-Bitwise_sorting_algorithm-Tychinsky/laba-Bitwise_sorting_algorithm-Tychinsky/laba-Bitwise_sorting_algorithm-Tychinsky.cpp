#include <iostream>
#include <vector>
#include "Radix.h"

int main() {
    setlocale(LC_ALL, "ru");
    //1. [10 баллов] Требуется реализовать алгоритм побитовой (не путать с поразрядной) сортировки массива. 
    // Также, для проверки работы алгоритма требуется написать функцию проверки отсортированного массива на упорядоченность. Достаточно сортировки неотрицательных чисел.
    srand((unsigned int)time(0));
    //std::vector<int> ms = CreateMassive(10, 10, -10);
    std::vector<int> ms = { 8, 7, 6, 4, 5, 0, 4, 1 };
    //std::vector<int> ms = {3,-5,-1,7,-2,0,4,-8,2};
    //-8 - 5 - 1 - 2 7 0 4 3 2




    std::cout << "Первоначальный массив: \n";
    Print(ms);

    BitSorting(ms);

    std::cout << std::endl << ((IsOrderly(ms)) ? "Массив отсортирован" : "Массив НЕ отсортирован") << std::endl;
  
    std::cout << "\nОтсортированный массив:\n";
    Print(ms);
    std::cout << std::endl;

    return 0;
}