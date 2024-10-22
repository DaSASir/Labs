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

    CreateMatrixCities(matrix, gauge, 9, 1);//пусть цены варьируются от 1 до 9
    cout << endl << "Вывод нашей матрицы путей: " << endl;
    Print(matrix, gauge);

    int entry_city = CreateEntryCity(gauge);//начальный город

    //схемы путей
    int** path = CreatePathMatrix(gauge, entry_city);


  

    
    
    
    





    cout << endl << "Вывод матрицы путей: " << endl;
    for (int i = 0; i < Factorial(gauge - 1); i++) {
        for (int j = 0; j < gauge + 1; j++) {
            cout << path[i][j] << " ";
        }cout << endl;
    }

}