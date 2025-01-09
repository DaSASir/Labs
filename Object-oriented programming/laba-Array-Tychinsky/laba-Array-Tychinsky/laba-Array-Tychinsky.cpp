#include <iostream>
#include "Array.h"

int main() {
    setlocale(LC_ALL, "ru");

    Array<int> boo(5);
    for (int i = 0; i < 5; i++) 
        boo[i] = i;
    boo[0] = 3;
    boo[1] = 3;
    std::cout << boo;
    const Array<int>::Iterator it = boo.begin();
    const Array<int>::Iterator it2 = boo.begin() + 2;
    const Array<int>::Iterator it3 = boo.end();
    boo.DelItRange(it, it3);
    

    std::cout << boo;


    return 0;
     
    int* mas = new int[10];
    for (int i = 0; i < 10; i++)
        mas[i] = i + 1;

    Array<int> A(mas, 10);

    std::cout << "Size: " << A.GetSize() << "\n";
    A.Print();

    std::cout << "Find 5 - " << A.FindElement(5);

    std::cout << "\nCreate new Array:\n";
    Array<int> A2;
    A2.Scan();
    std::cout << "Print: ";
    A2.Print();

    std::cout << "\nPrint swap A and A2: ";
    A.Swap(A2);
    A.Print();

    std::cout << "\nPrint Sort: ";
    A.Sorting();
    A.Print();

    std::cout << "\nGet element - 52 to index: ";
    A.AddIndex(1, 52);
    A.Print();

    std::cout << "\nDelIndex 1: ";
    A.DelIndex(1);
    A.Print();


    Array<int> A3 = A;
    std::cout << "\nA3 = ";
    A3.Print();

    return 0;
}
