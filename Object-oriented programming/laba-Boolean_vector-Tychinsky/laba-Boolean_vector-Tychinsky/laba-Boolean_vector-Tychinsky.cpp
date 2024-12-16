#include <iostream>
#include <vector>
#include <cstring>
#include "Vector.h"

typedef unsigned char UC;

int main() {
    setlocale(LC_ALL, "ru");
    
    

    char* array = new char[8];
    for (int i = 0; i < 8; i++)
        array[i] = i % 2;

    BoolVector bv1;

    bv1.Scan();

    bv1.Print();
    bv1.Inversion();
    bv1.Print();

    std::cout << "\nCountOfBit and WeightVector : ";
    std::cout << bv1.CountOfBit() << " " << bv1.WeightVector();


    return 0;
}