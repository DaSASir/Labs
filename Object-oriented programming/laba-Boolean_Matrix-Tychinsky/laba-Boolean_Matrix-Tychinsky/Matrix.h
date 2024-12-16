#pragma once
#include "../../laba-Boolean_vector-Tychinsky/laba-Boolean_vector-Tychinsky/Vector.h"

class BoolMatrix {
public:
	// конструкторы (по умолчанию, с параметрами (количество строк/столбцов и значения разрядов), конструктор из матрицы char, конструктор копирования);
	BoolMatrix();
	BoolMatrix(const int col_count, const int row_count, const bool value);
	BoolMatrix(const char** matrix, const int col_count, const int row_count);
	BoolMatrix(const BoolMatrix& other);
	// деструктор;
	~BoolMatrix();
	//получение числа строк и столбцов матрицы;
	int GetAmountOfRows() const;
	int GetAmountOfCols() const;
	//обмен содержимого с другой матрицей (swap);
	void Swap(BoolMatrix& other);
	//ввод/вывод в консоль (потоковый);
	void Print() const;
	//вес матрицы (количество единичных компонент);
	int Weight() const;
	//конъюнкция всех строк (возвращает булев вектор);
	BoolVector ConjunctionOfRows();
	//дизъюнкция всех строк (возвращает булев вектор);
	BoolVector DisjunctionOfRows();
	//вес j-ой строки;
	int Weight(const int index_row) const;
	//инверсия в i-ой компоненты j-ой строки;
	void Inversion(const int index_i, const int index_j);
	//инверсия k компонент j-ой строки, начиная с i-ой компоненты;
	void Inversion(const int index_i, const int index_j, const int k);
	//установка в 0/1 i-ой компоненты j-ой строки;
	void Set(const bool value, const int index_i, const int index_j);
	//установка в 0/1 k компонент j-ой строки, начиная с i-ой компоненты;
	void Set(const bool value, const int index_i, const int index_j, const int k);

	//присваивание (=);
	BoolMatrix& operator = (const BoolMatrix& other);
	//получение строки([]);
	BoolVector& operator [] (const int index);
	const BoolVector& operator [] (const int index) const;
	//построчное побитовое умножение(&, &=);
	BoolMatrix operator & (const BoolMatrix& other) const;
	BoolMatrix& operator &= (const BoolMatrix& other);
	//построчное побитовое сложение(| , |=);
	BoolMatrix operator | (const BoolMatrix& other) const;
	BoolMatrix& operator |= (const BoolMatrix& other);
	//построчное побитовое исключающее ИЛИ(^, ^=);
	BoolMatrix operator ^ (const BoolMatrix& other) const;
	BoolMatrix& operator ^= (const BoolMatrix& other);
	//построчная побитовая инверсия(~).
	BoolMatrix operator ~ () const;

private:
	BoolVector* m_count_vectors = nullptr;
	int m_amount_row, m_amount_col;
};

std::istream& operator >> (std::istream& stream, BoolMatrix& other);
std::ostream& operator << (std::ostream& stream, const BoolMatrix& other);