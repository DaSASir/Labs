#include <iostream>
#include <vector>
#include "Top.h"

int main() {
	setlocale(LC_ALL, "ru");

	Graph gg(6);

    gg.AddEdge(5, 2);
    gg.AddEdge(5, 0);
    gg.AddEdge(4, 0);
    gg.AddEdge(4, 1);
    gg.AddEdge(2, 3);
    gg.AddEdge(3, 1);

    gg.TopSorting();
    
    std::cout << "\n";

    BoolMatrix m(6, 6, 0);

    m.Inversion(2, 5);
    m.Inversion(0, 5);
    m.Inversion(0, 4);
    m.Inversion(1, 4);
    m.Inversion(3, 2);
    m.Inversion(1, 3);



	return 0;
}