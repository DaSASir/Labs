#pragma once

std::vector<int> CreateMassive(const int amount, const int max, const int min);

void PrintArray(const std::vector<int>& mas);

bool IsOrderly(const std::vector<int>& mas);

void BitSorting(std::vector<int>& mas);

void SymbolicSorting(std::vector<int>& mas, int& l, int& r);

void MinusSorting(std::vector<int>& mas, const int left, const int right, int mask);
void PlusSorting(std::vector<int>& mas, const int left, const int right, int mask)