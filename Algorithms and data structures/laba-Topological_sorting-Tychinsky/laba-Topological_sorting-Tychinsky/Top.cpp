#include <iostream>
#include <vector>
#include "Top.h"


void DFS(std::vector<std::vector<int>>& graph, std::vector<bool> visited, std::vector<int>& order, int index) {
	visited[index] = 1;

	for (int to : graph[index])
		if (!visited[to])
			DFS(graph, visited, order, to);

	order.push_back(index);
}

void TopSort(std::vector<std::vector<int>>& graph, std::vector<bool> visited, std::vector<int>& order, const int size) {
	for (int i = 0; i < size; i++)
		if (!visited[i])
			DFS(graph, visited, order, i);

	std::reverse(order.begin(), order.end());
}

std::vector<std::vector<int>> CreateGraph(const BoolMatrix& matrix) {
	std::vector<std::vector<int>> a;

	return a;
}