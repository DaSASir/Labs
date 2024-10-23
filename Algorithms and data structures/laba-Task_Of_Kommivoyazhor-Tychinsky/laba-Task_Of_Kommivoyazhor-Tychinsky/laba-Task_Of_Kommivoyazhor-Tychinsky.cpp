#include <iostream>
#include <time.h>
#include "kommivoyazhor.h"

int main() {
    setlocale(LC_ALL, "ru");

    int gauge;//кол-во городов
    std::cout << "Введите кол-во городов: ";
    std::cin >> gauge;

    clock_t start_time, stop_time;//начинаем считать время
    start_time = clock();


    int** matrix = CreateMatrixCities(gauge, 9, 1);//создание матрицы стоимости

    std::cout << std::endl << "Вывод нашей матрицы путей: " << std::endl;
    Print(matrix, gauge);

    int entry_city = CreateEntryCity(gauge);//начальный город

    int min_weight = 0;
    int* min_path = FindMinimumPathWeight(matrix, gauge, entry_city, min_weight);
    std::cout << std::endl << "Минимальная стоимость пути: " << min_weight << std::endl;

    std::cout << "Путь с минимальной стоимостью: ";
    for (int i = 0; i < gauge + 1; i++)
        std::cout << min_path[i] << " ";
    std::cout << std::endl;

    stop_time = clock();//заканчиваем считать время
    double time_work = (double)(stop_time - start_time) / CLOCKS_PER_SEC;

    std::cout << std::endl << "Время нахождения минимального пути с количеством городов = " << gauge << ": " << time_work << "s" << std::endl;

    //Эвристический метод
    clock_t start_time_e, stop_time_e;//начинаем считать время
    start_time_e = clock();

    int min_path_e;
    int* path_e = HeuristicAlgorithm1(gauge, matrix, min_path_e, entry_city);

    std::cout << std::endl << "Эвристический способ решения: " << std::endl;
    std::cout << std::endl << "Путь с минимальной стоимостью: ";
    for (int i = 0; i <= gauge; i++)
        std::cout << path_e[i] << " ";
       
    std::cout << std::endl << "Минимальная стоимость пути: " << min_path_e << std::endl;

    stop_time_e = clock();//заканчиваем считать время
    double time_work_e = (double)(stop_time_e - start_time_e) / CLOCKS_PER_SEC;

    std::cout << std::endl << "Время нахождения минимального пути эвристическим методом: " << time_work_e << "s" << std::endl;


    delete[] path_e, min_path;
    DeleteMatrix(matrix, gauge);
}