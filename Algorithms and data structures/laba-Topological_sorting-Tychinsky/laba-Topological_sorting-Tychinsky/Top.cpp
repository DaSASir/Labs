#include <iostream>
#include <vector>
#include "Top.h"

Graph::Graph(const int vertices):m_vertices(vertices) {
    std::vector<std::vector<int>> back(m_vertices);
    m_graph = back;
}
/*
Graph::Graph(const BoolMatrix& matrix) {
    if (matrix.GetAmountOfCols() != matrix.GetAmountOfRows())
        std::cout << "ERROR!!!!!\n";

    m_vertices = matrix.GetAmountOfCols();

    std::vector<std::vector<int>> back(m_vertices);
    m_graph = back;
}

*/

void Graph::AddEdge(const int vertices,const int edge) {
    m_graph[vertices].push_back(edge);
}
/*
void Graph::AddEdges(const BoolMatrix& matrix) {
    for (int step = 0; step < 6; step++) {
        int index = 6;
        int mask = 1 << index;
        int weight = 0;
        while (weight != matrix.Weight(step)) {
            if ((matrix[step] & mask)) {
                weight++;
                AddEdge(step, index);
            }
            index--;
            mask = mask << index;
        }
    }
}

*/

void Graph::DFS(const int index, std::vector<bool>& visited, std::vector<int>& order) {
    visited[index] = true;

    for (int to : m_graph[index])
        if (!visited[to])
            DFS(to, visited, order);

    order.push_back(index);
}

void Graph::TopSorting() {
    std::vector<int> order;
    std::vector<bool> visited(m_vertices, false);

    for (int i = 0; i < m_vertices; i++)
        if (!visited[i])
            DFS(i, visited, order);

    std::reverse(order.begin(), order.end());

    for (int x : order) std::cout << x << " ";
}

