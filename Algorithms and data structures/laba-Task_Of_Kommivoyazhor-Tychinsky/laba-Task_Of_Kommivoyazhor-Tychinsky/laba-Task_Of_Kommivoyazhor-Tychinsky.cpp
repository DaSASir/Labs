#include <iostream>
#include <time.h>
#include "kommivoyazhor.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int gauge;//кол-во городов
    cout << "Введите кол-во городов: ";
    cin >> gauge;

    clock_t start_time, stop_time;//начинаем считать время
    start_time = clock();


    int** matrix = CreateMatrixCities(gauge, 9, 1);//создание матрицы стоимости

    cout << endl << "Вывод нашей матрицы путей: " << endl;
    Print(matrix, gauge);

    int entry_city = CreateEntryCity(gauge);//начальный город

    int** path = CreatePathMatrix(gauge, entry_city);//все возможные пути
    
    /*
    cout << endl << "Вывод матрицы путей: " << endl;
    PrintPath(path, gauge);
    */

    int index_min_path;
    int min_path = MinimumPathWeight(matrix, path, gauge, index_min_path);//нахождение минимальной стоимости и пути
    cout << endl << "Минимальная стоимость пути: " << min_path << endl;

    cout << "Путь с минимальной стоимостью: ";
    for (int i = 0; i < gauge + 1; i++)
        cout << path[index_min_path][i] << " ";
    cout << endl;

    stop_time = clock();//заканчиваем считать время
    double time_work = (double)(stop_time - start_time) / CLOCKS_PER_SEC;

    cout << endl << "Время нахождения минимального пути с количеством городов = " << gauge << ": " << time_work << "s" << endl;

    //Эвристический метод
    clock_t start_time_e, stop_time_e;//начинаем считать время
    start_time_e = clock();

    int min_path_e;
    int* path_e = HeuristicAlgorithm1(gauge, matrix, min_path_e, entry_city);

    cout << endl << "Эвристический способ решения: " << endl;
    cout << endl << "Путь с минимальной стоимостью: ";
    for (int i = 0; i <= gauge; i++)
        cout << path_e[i] << " ";
       
    cout << endl << "Минимальная стоимость пути: " << min_path_e << endl;

    stop_time_e = clock();//заканчиваем считать время
    double time_work_e = (double)(stop_time_e - start_time_e) / CLOCKS_PER_SEC;

    cout << endl << "Время нахождения минимального пути эвристическим методом: " << time_work_e << "s" << endl;


    delete[] path_e;
    DeleteMatrix(matrix, gauge);
    DeleteMatrix(path, Factorial(gauge - 1));
}