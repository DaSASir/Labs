#include <iostream>
#include <time.h>
#include "kommivoyazhor.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int gauge;//кол-во городов
    cout << "Введите кол-во городов: ";
    cin >> gauge;

    int** matrix = CreateMatrixCities(gauge, 9, 1);//создание матрицы стоимости

    cout << endl << "Вывод нашей матрицы путей: " << endl;
    Print(matrix, gauge);

    int entry_city = CreateEntryCity(gauge);//начальный город

    int** path = CreatePathMatrix(gauge, entry_city);//все возможные пути
    
    cout << endl << "Вывод матрицы путей: " << endl;
    PrintPath(path, gauge);

    int min_path = MinimumPathWeight(matrix, path, gauge);
    cout << endl <<  "Минимальная стоимость пути: " << min_path;
    cout << endl;

}