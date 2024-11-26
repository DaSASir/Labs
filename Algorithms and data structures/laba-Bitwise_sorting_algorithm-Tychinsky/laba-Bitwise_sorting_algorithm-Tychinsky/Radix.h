#pragma once

std::vector<int> CreateMassive(const int amount, const int max, const int min);

void PrintArray(const std::vector<int>& mas);

bool IsOrderly(const std::vector<int>& mas);

void BitSorting(std::vector<int>& mas, const int max_elemnt);

void SymbolicSorting(std::vector<int>& mas, int& l, int& r);
