#include <iostream>
#include <vector>
#include <cstring>
#include "Vector.h"

typedef unsigned char UC;

int main() {
    setlocale(LC_ALL, "ru");
    

    BoolVector bv1;

    bv1.Scan();

    bv1.Print();
    bv1.Inversion();
    bv1.Print();

    std::cout << "\nCountOfBit and WeightVector : ";
    std::cout << bv1.CountOfBit() << " " << bv1.WeightVector();


    return 0;
}