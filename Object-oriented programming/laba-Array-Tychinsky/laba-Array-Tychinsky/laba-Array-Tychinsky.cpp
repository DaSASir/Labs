#include <iostream>
#include <vector>
#include "Array.h"

//найти само встречабщийся элемент(выдаем первый)
template <typename T>
Array<T> fromStdVector(std::initializer_list<T> list)
{
    return Array<T>(list.begin(), list.size());
}

template <typename T>
T FindMostPopularEl(const Array<T>& array) {
    if (array.GetSize() == 0) {
        std::cerr << "Ошибка йоу!!! размер массива не может быть равен нулю" << std::endl;
        return 0;
    }
    
    Array<T> foo(array);

    int most = 0;
    int count1 = 0;

    for (int i = 0; i < foo.GetSize(); i++) {
        int count2 = 0;
        while (foo.DelValue(array[i])) 
            count2++;

        if (count2 > count1) {
            most = i;
            count1 = count2;
        }

    }

    return array[most];
}

int main() {
    setlocale(LC_ALL, "ru");
    
    std::cout << "\nElement:" << FindMostPopularEl(Array<int>(0));
    std::cout << "\nElement:" << FindMostPopularEl(fromStdVector({ "a","a","b", "b"}));

    

    int* sss = new int[6];
    std::vector<int> vec = { 1 , 1 ,2 ,3 ,4 , 1 };
    for (int i = 0; i < vec.size(); i++)
        sss[i] = vec[i];


    std::cout << "\nElement:" << FindMostPopularEl(Array<int>(sss, vec.size()));



    //Array<int> R1(6);
    //Array<int> R2(4);

    //for (int i = 0; i < R1.GetSize(); i++)
    //    R1[i] = i + 1;
    //for (int i = 0; i < R2.GetSize(); i++)
    //    R2[i] = i + 2;

    //std::cout << "R1: " << R1;

    //std::cout << "\nElement:" << FindMostPopularEl(R1);

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
