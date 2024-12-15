#pragma once
#include "..\..\..\Object-oriented programming\laba-Boolean_Matrix-Tychinsky\laba-Boolean_Matrix-Tychinsky\Matrix.h"
//#include "..\..\..\Object-oriented programming\laba-List-Tychinsky\laba-List-Tychinsky\List.h"

void DFS(std::vector<std::vector<int>>& graph, 
	std::vector<bool> visited, std::vector<int>& order, int index);

void TopSort(std::vector<std::vector<int>>& graph,
	std::vector<bool> visited, std::vector<int>& order, const int size);

std::vector<std::vector<int>> CreateGraph(const BoolMatrix& matrix);