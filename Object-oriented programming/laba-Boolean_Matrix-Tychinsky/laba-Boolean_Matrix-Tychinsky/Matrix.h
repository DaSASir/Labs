#pragma once
#include "C:\GitHub_Repositories\Labs\Object-oriented programming\laba-Boolean_vector-Tychinsky\laba-Boolean_vector-Tychinsky\Vector.h"

class BoolMatrix {
	typedef unsigned int UI;

public:
	// конструкторы (по умолчанию, с параметрами (количество строк/столбцов и значения разрядов), конструктор из матрицы char, конструктор копирования);
	BoolMatrix();
	BoolMatrix(const UI col_count, const UI row_count, const bool value);
	BoolMatrix(const char** matrix, const UI col_count, const UI row_count);
	BoolMatrix(const BoolMatrix& other);
	// деструктор;
	~BoolMatrix();
	//получение числа строк и столбцов матрицы;
	int GetAmountOfRows();
	int GetAmountOfCols();
	//обмен содержимого с другой матрицей (swap);
	void Swap(BoolMatrix& other);
	//ввод/вывод в консоль (потоковый);
	void Print();
	//вес матрицы (количество единичных компонент);
	int Weight();
	//конъюнкция всех строк (возвращает булев вектор);
	
	//дизъюнкция всех строк (возвращает булев вектор);
	
	//вес j-ой строки;
	int Weight(const UI index_row);
	//инверсия в i-ой компоненты j-ой строки;
	void Inversion(const int index_i, const int index_j);
	//инверсия k компонент j-ой строки, начиная с i-ой компоненты;
	void Inversion(const int index_i, const int index_j, const int k);
	//установка в 0/1 i-ой компоненты j-ой строки;
	void Set(const bool value, const int index_i, const int index_j);
	//установка в 0/1 k компонент j-ой строки, начиная с i-ой компоненты;
	void Set(const bool value, const int index_i, const int index_j, const int k);

	//присваивание (=);
	
	//получение строки([]);
	
	//построчное побитовое умножение(&, &=);
	
	//построчное побитовое сложение(| , |=);
	
	//построчное побитовое исключающее ИЛИ(^, ^=);
	
	//построчная побитовая инверсия(~).






private:
	BoolVector* m_count_vectors = nullptr;
	UI m_amount_row, m_amount_col;
};
