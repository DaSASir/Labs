#pragma once

//#1
void TheInitialSequence(int* a, const int n);

void ShellAlgorithm(int t, int* h, int* a, int n);

void PrintArray(int mas_cheese[], const int n);

bool IsOrderly(int* mas_cheese,  int n);

//#2
int** CreateDiffArrays();

void DeleteMatrix(int** a, const int n);

//другие формулы для выбора длин шагов в алгоритме Шелла
void SequenceWithLogarithms(int* a, const int n);
void TheWhipSequence(int* a, const int n);
void TheSedgwickSequence(int* a, const int n);