#include <iostream>
#include <cstring>
#include "Vector.h"

int main() {
    setlocale(LC_ALL, "ru");
    
    BoolVector b;
    b.Print();

    BoolVector b2(8);
    b2.Print();

    BoolVector b3(7, 0);
    b3.Print();

    std::string st = "101010";
    char* arr = new char[6];
    for (int i = 0; i < 6; i++)
        arr[i] = st[i];
    BoolVector b4(arr, 6);
    b4.Print();

    BoolVector b5(b2);
    b5.Print();
    
    std::cin >> b2;
    std::cout << b2;
    //b2.Scan();
    //b2.Print();

    std::cout << "CountOfBit b3 = " << b3.CountOfBit() << "\n";
    std::cout << "CountOfCell b3 = " << b3.CountOfCell() << "\n";
    std::cout << "WeightVector b3 = " << b3.WeightVector() << "\n";

    b3.Inversion(2);
    b3.Print();

    return 0;
}