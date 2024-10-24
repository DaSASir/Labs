#include <iostream>
#include <fstream>
#include <time.h>
#include "Shell.h"
#define _CRT_SECURITYCRITICAL_ATTRIBUTE

int main() {
    setlocale(LC_ALL, "ru");

    //1. [10 баллов] Требуется реализовать алгоритм Шелла для сортировки массива.
    int array_of_int[] = { 9,8,7,6,5,4,3,2,1 };
    std::cout << "Первоначальный массив: ";
    PrintArray(array_of_int, 9);

    std::cout << std::endl << std::endl;
    ShellAlgorithm(array_of_int, 9);
    if (!IsOrderly(array_of_int, 9))
        std::cout << "Массив не упорядочен!!!" << std::endl;
    else {
        std::cout << "Массив после сортировки: ";
        PrintArray(array_of_int, 9);
        std::cout << std::endl;
    }
    
    //2. [10 баллов] Дополнительно:
    int** different_arrays = CreateDiffArrays();

    double average_time = CreateAverageTime(different_arrays);
    std::cout << "Среднее время работы всех алгоритмов - " << average_time;
    


    delete[]array_of_int;
    DeleteMatrix(different_arrays, 9);
}