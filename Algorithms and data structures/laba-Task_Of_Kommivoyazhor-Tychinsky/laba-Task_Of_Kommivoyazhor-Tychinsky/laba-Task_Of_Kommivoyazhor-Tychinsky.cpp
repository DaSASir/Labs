#include <iostream>
#include <time.h>
#include <vector>
#include "kommivoyazhor.h"

int main() {
    setlocale(LC_ALL, "ru");
    srand((unsigned int)time(0));

    int gauge;//кол-во городов
    std::cout << "Введите кол-во городов: ";
    std::cin >> gauge;

    clock_t start_time = clock();

    std::vector<std::vector<int>> matrix = CreateMatrixCities(gauge, 9, 1);;

    std::cout << std::endl << "Вывод нашей матрицы путей: " << std::endl;
    Print(matrix);

    int entry_city = CreateEntryCity(gauge);

    int min_weight = 0;
    std::vector<int> min_path = FindMinimumPathWeight(matrix, gauge, entry_city, min_weight);
    std::cout << "\nМинимальная стоимость пути: " << min_weight;

    std::cout << "\nПуть с минимальной стоимостью: ";
    for (int city : min_path)
        std::cout << city << " ";


    clock_t stop_time = clock();
    double time_work = static_cast<double>(stop_time - start_time) / CLOCKS_PER_SEC;

    std::cout << "\nВремя нахождения минимального пути с количеством городов = " << gauge << ": " << time_work << "s" << std::endl;


    //Эвристический метод
    std::cout << "\nЭвристический способ решения: \n";
    clock_t start_time_e = clock();

    int min_path_e;
    std::vector<int> path_e = HeuristicAlgorithm1(gauge, matrix, min_path_e, entry_city);

    std::cout << "\nПуть с минимальной стоимостью: ";
    for (int city: path_e)
        std::cout << city << " ";
       
    std::cout << "\nМинимальная стоимость пути: " << min_path_e << std::endl;

    clock_t stop_time_e = clock();
    double time_work_e = static_cast<double>(stop_time_e - start_time_e) / CLOCKS_PER_SEC;

    std::cout << "\nВремя нахождения минимального пути эвристическим методом: " << time_work_e << "s" << std::endl;
    

    return 0;
}