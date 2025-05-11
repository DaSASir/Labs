#include <iostream>
#include <vector>
#include "Top.h"

int main() {
	setlocale(LC_ALL, "ru");
    const int size = 6;

	Graph gg(size);

    gg.AddEdge(5, 2);
    gg.AddEdge(5, 0);
    gg.AddEdge(4, 0);
    gg.AddEdge(4, 1);
    gg.AddEdge(2, 3);
    gg.AddEdge(3, 1);

    gg.TopSorting();
    
    std::cout << "\n";

    

	return 0;
}