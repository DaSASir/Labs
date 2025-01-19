#include <iostream>
#include "List.h"

int main() {
    setlocale(LC_ALL, "ru");
    
    int* arr = new int[7];
    for (int i = 0; i < 7; i++)
        arr[i] = (i + 1);

    List<int> l;
    l.AddTail(21);
    l.AddTail(52);
    l.AddTail(228);

    l.Print();
    std::cout << "Size of l1 - " << l.GetSize() << std::endl;

    List<int> l2(arr, 7);
    l2.Print();
    std::cout << "Size of l2 - " << l2.GetSize() << std::endl;

    List<int> l3(l2);
    //l3.Print();
    //std::cout << "Size of l3 - " << l3.GetSize() << std::endl;

    std::cout << l3 << "Size of l3 - " << l3.GetSize() << std::endl;;


    /*
    List<int> l4;
    l4.Scan();
    l4.Print();
    std::cout << "Size of l4 - " << l4.GetSize() << std::endl;

    l4.Sorting();
    l4.Print();

    l4.DelHead();
    l4.Print();
    */
    

    //std::cout << "CHECKIN!!!";

    return 0;
}