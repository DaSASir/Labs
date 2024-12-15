#include <iostream>
#include <vector>
#include "Top.h"

int main() {
	setlocale(LC_ALL, "ru");

	int element_count = 7;

	BoolMatrix bool_matrix(element_count, element_count, 0);
	bool_matrix.Print();

	std::vector<int> order;
	std::vector<bool> visited(element_count, 0);
	std::vector<std::vector<int>> graph = CreateGraph(bool_matrix);

	TopSort(graph, visited, order, element_count);

	std::cout << "\nВывод TopSorting: ";
	for (int i : order)
		std::cout << i << " ";

	return 0;
}