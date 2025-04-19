#include <iostream>
#include <cstring>
#include "Vector.h"

int main() {
    setlocale(LC_ALL, "ru");
    
    constexpr int size_bv = 13;

    BoolVector B(size_bv, 1);
    
    std::cout << "Count of cell: " << B.CountOfCell() << std::endl;
    std::cout << "Count of bit: " << B.CountOfBit() << std::endl;

    std::cout << "Vector: " << B; B.Print();
    std::cout << "Weight: " << B.WeightVector();



    return 0;
}