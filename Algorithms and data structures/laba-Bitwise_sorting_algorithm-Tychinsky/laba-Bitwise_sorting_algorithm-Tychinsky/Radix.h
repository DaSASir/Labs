#pragma once

std::vector<int> CreateMassive(const int amount, const int max, const int min);

void Print(const std::vector<int>& mas);

bool IsOrderly(const std::vector<int>& mas);

void BitSorting(std::vector<int>& mas);
void SortingPositive(std::vector<int>& mas,
	const int left, const int right, const int mask);
