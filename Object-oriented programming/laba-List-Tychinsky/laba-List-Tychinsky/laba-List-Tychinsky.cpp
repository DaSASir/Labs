#include <iostream>
#include "List.h"

int main() {
    setlocale(LC_ALL, "ru");
    
    int* arr = new int[7];
    for (int i = 0; i < 7; i++)
        arr[i] = (i + 1);

    List<int> l(arr, 7);
    l.Print();

    return 0;
}