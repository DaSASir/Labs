#include <iostream>
#include <fstream>
#include <time.h>
#include <cmath>
#include <vector>
#include "Shell.h"

int main() {
    setlocale(LC_ALL, "ru");

    //1. [10 баллов] Требуется реализовать алгоритм Шелла для сортировки массива.
    int array_of_int[] = { 9,8,7,6,5,4,3,2,1 };
    std::cout << "Первоначальный массив: ";
    PrintArray(array_of_int, 9);

    std::cout << std::endl << std::endl;
    TheInitialSequence(array_of_int, 9);
    if (!IsOrderly(array_of_int, 9))
        std::cout << "Массив не упорядочен!!!" << std::endl;
    else {
        std::cout << "Массив после сортировки: ";
        PrintArray(array_of_int, 9);
        std::cout << std::endl;
    }
    
    //2. [10 баллов] Дополнительно:
    int** diff_array = CreateDiffArrays();

    std::vector<double> average_time = CreateAverageTime(diff_array);
    
    std::cout << "Среднее время алгоритмов: \n";
    for(int i = 0; i < average_time.size(); i ++)
        std::cout << average_time[i] << "\n";

    for (int i = 0; i < 9; i++)
        delete[] diff_array[i];
    delete[]array_of_int, diff_array;
}