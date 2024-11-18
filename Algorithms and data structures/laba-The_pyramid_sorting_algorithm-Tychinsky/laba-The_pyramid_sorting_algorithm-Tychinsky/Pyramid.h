#pragma once

std::vector<int> CreateMassive(const int amount);

void PrintArray(const std::vector<int>& mas);

bool IsOrderly(const std::vector<int>& mas);


void PyramidSorting(std::vector<int>& mas);
void Sift1(std::vector<int>& mas, const int size, int index);
void Sift2(std::vector<int>& mas, const int size, int index);