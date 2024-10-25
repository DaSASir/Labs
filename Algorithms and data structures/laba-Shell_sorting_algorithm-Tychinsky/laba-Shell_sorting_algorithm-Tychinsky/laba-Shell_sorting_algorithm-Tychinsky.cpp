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
    SequenceWithLogarithms(array_of_int, 9);

    if (!IsOrderly(array_of_int, 9))
        std::cout << "Массив не упорядочен!!!" << std::endl;
    else {
        std::cout << "Массив после сортировки: ";
        PrintArray(array_of_int, 9);
        std::cout << std::endl;
    }
    
    //2. [10 баллов] Дополнительно:
    std::cout << "\nВторой этап: \n";
    int** diff_array = CreateDiffArrays();

    std::vector<double> average_time;

    int size[] = { 10000 ,10000 ,10000 ,
                   100000 ,100000 ,100000 ,
                   1000000 ,1000000 ,1000000 };

    for (int j = 0; j < 9; j++) {
        time_t start = clock();

        SequenceWithLogarithms(diff_array[j], size[j]);
        //TheInitialSequence(copy[j], size[j]);
        //SequenceWithLogarithms(copy[j], size[j]);
        //TheWhipSequence(copy[j], size[j]);
        //TheSedgwickSequence(copy[j], size[j]);

        time_t stop = clock();
        double time = (double)(stop - start) / CLOCKS_PER_SEC;

        if (!IsOrderly(diff_array[j], size[j]))
            std::cout << "Массив не упорядочен!!!" << j << std::endl;
        else 
            average_time.push_back(time);
    }

    std::cout << "Вывод времени каждого массива:";
    for (int i = 0; i < average_time.size(); i++) {
        if (i % 3 == 0) 
            std::cout << "\n";

        std::cout << average_time[i] << "s ";
        
    }

    std::cout << "\nВывод среднего времени:\n";

    average_time.push_back(0.0);
    for (int i = 0; i < average_time.size() - 1; i++) 
        average_time[average_time.size() - 1] += average_time[i];
        
    
    std::cout << average_time[average_time.size() - 1] / (average_time.size() - 1) << "s\n";
    

}