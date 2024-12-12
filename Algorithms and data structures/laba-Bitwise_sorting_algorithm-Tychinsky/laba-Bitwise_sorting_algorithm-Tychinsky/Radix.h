#pragma once

std::vector<int> CreateMassive(const int amount, const int max, const int min);

void Print(const std::vector<int>& mas);

bool IsOrderly(const std::vector<int>& mas);

void BitSorting(std::vector<int>& mas);

void Sorting(std::vector<int>& mas,
	const int left, const int right, const int mask);

double MiddleTimeOfFile();