#include <iostream>
#include "Fraction.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    Fraction f1, f2(3,5), f3;

    cout << "Введите дробь f1: " << endl; 
    f1.Scan();

    cout << endl << "Вывод дробей f1 и f2: " << endl;
    cout << "f1: "; 
    f1.Print(); 
    cout << "f2: "; 
    f2.Print();

    cout << endl << "f1 + f2: ";
    f3 = f1 + f2; 
    f3.Print();

    cout << endl << "f1 - f2: ";
    f3 = f1 - f2; 
    f3.Print();

    cout << endl << "f1 * f2: ";
    f3 = f1 * f2; 
    f3.Print();

    cout << endl << "f1 / f2: ";
    f3 = f1 / f2; 
    f3.Print();

    cout << endl << "f1 > f2? : " << (f1 > f2 ? "ВЕРНО" : "НЕВЕРНО");
    cout << endl << "f1 < f2? : " << (f1 < f2 ? "ВЕРНО" : "НЕВЕРНО");
    cout << endl << "f1 == f2? : " << (f1 == f2 ? "ВЕРНО" : "НЕВЕРНО");
    cout << endl << "f1 != f2? : " << (f1 != f2 ? "ВЕРНО" : "НЕВЕРНО");

    cout << endl << endl;
    int k = 2;
    f3 = f2 + k;
    cout << "f2 + 2 = ";
    f3.Print();

    cout << endl;
    f3.WholePartPrint();
    cout << endl << endl;;

    k = 3;
    f3 = f3 - k;
    cout << "f2 + 2 - 3 = ";
    f3.Print();
}