#include <iostream>
#include "Fraction.h"

int main() {
    setlocale(LC_ALL, "ru");

    Fraction f1, f2(3,5), f3;

    std::cout << "Введите дробь f1: " << std::endl;
    f1.Scan();

    std::cout << std::endl << "Вывод дробей f1 и f2: " << std::endl;
    std::cout << "f1: ";
    f1.Print(); 
    std::cout << "f2: ";
    f2.Print();

    std::cout << std::endl << "f1 + f2: ";
    f3 = f1 + f2; 
    f3.Print();

    std::cout << std::endl << "f1 - f2: ";
    f3 = f1 - f2; 
    f3.Print();

    std::cout << std::endl << "f1 * f2: ";
    f3 = f1 * f2; 
    f3.Print();

    std::cout << std::endl << "f1 / f2: ";
    f3 = f1 / f2; 
    f3.Print();

    std::cout << std::endl << "f1 > f2? : " << (f1 > f2 ? "ВЕРНО" : "НЕВЕРНО");
    std::cout << std::endl << "f1 < f2? : " << (f1 < f2 ? "ВЕРНО" : "НЕВЕРНО");
    std::cout << std::endl << "f1 == f2? : " << (f1 == f2 ? "ВЕРНО" : "НЕВЕРНО");
    std::cout << std::endl << "f1 != f2? : " << (f1 != f2 ? "ВЕРНО" : "НЕВЕРНО");

    std::cout << std::endl << std::endl;
    int k = 2;
    f3 = f2 + k;
    std::cout << "f2 + 2 = ";
    f3.Print();

    std::cout << std::endl;
    f3.WholePartPrint();
    std::cout << std::endl << std::endl;

    k = 3;
    f3 = f3 - k;
    std::cout << "f2 + 2 - 3 = ";
    f3.Print();

    return 0;
}