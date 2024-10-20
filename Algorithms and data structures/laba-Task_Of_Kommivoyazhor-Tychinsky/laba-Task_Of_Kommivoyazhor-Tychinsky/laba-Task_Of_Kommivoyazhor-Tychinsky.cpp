#include <iostream>
#include <time.h>
#include "kommivoyazhor.h"

using namespace std;
int main() {
    setlocale(LC_ALL, "ru");

    int gauge;//кол-во городов
    cout << "Введите кол-во городов: ";
    cin >> gauge;

    int** matrix = new int* [gauge];//матрица стоимости путей

    Create_Matrix_of_cities(matrix, gauge, 9, 1);
    cout << endl << "Вывод нашей матрицы путей: " << endl;
    Print(matrix, gauge);

    int entry_city;//начальный город
    cout << "Введите начальный город: ";
    cin >> entry_city;
    while (entry_city < 1 || entry_city > gauge) {
        cout << "Введите еще раз начальный город: ";
        cin >> entry_city;
    }

    int* Path = new int[gauge + 1];//схема пути


}