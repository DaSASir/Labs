#include <iostream>
#include <functional>
#include <time.h>
#include <vector>
#include <array>
#include "List.h"

template<typename T>
void Assignment1(List<T>& list, const List<T>& other) {
    if (list != other) {
        list.Clear();
        for (int i = 0; i < other.GetSize(); i++) 
            list.AddTail(other[i]);
    }
}

template<typename T>
void Assignment2(List<T>& list, const List<T>& other) {
    if (&list == &other)
        return;

    list.Clear();
    for (int i = 0; i < other.GetSize(); i++)
        list.AddTail(other[i]);
}

double test(int size, typename std::function<void(List<int>&, const List<int>&)> func)
{
    std::vector<int> data(size, 0);

    List<int> ls1(data.data(), size);
    data.back() = 1;
    List<int> ls2(data.data(), size);

    time_t start, stop;
    time(&start);

    func(ls2, ls1);

    time(&stop);
    return double(stop - start);
}

int main() {
    setlocale(LC_ALL, "ru");

    std::vector<int> v1 = { 1, 3 , 5 , 52, 7,8 };
    List<int> L1(v1.data(), v1.size());

    std::cout << L1;
    L1.DelFromKey(5);
    std::cout << L1;








    return 0;

    std::vector<int> a = { 1,2,3,4 };
    std::vector<int> b = { 1,2,3,4 };

    List<int> A(a.data(),a.size());
    List<int> B(b.data(),b.size());

    std::cout << "\na == b ? - " << (A == B);

    Assignment2(A, A);
    std::cout << "\n" << A;
    std::cout << "\na == b ? - " << (A == B);

    return 0;







    std::array<double, 2> avgTime = {0, 0};
    int runs = 100;
    int size = 3000;
    for (int i = 0; i < runs; ++i) {
        avgTime[0] += test(size, Assignment1<int>);
        avgTime[1] += test(size, Assignment2<int>);
    }

    for (int j = 0; j < avgTime.size(); ++j) {
        std::cout << avgTime[j] / runs << "\n";
    }

    return 0;
}