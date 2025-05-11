#pragma once
//#include "..\..\..\Object-oriented programming\laba-Boolean_Matrix-Tychinsky\laba-Boolean_Matrix-Tychinsky\Matrix.h"
//#include "..\..\..\Object-oriented programming\laba-List-Tychinsky\laba-List-Tychinsky\List.h"

class Graph {
public:
	Graph(const int vertices);
	//Graph(const BoolMatrix& matrix);

	void AddEdge(const int vertices, const int edge);
	//void AddEdges(const BoolMatrix& matrix);

	void DFS(const int index, std::vector<bool>& visited, std::vector<int>& order);
	void TopSorting();

private:
	int m_vertices = 0;
	std::vector<std::vector<int>> m_graph;
	
};