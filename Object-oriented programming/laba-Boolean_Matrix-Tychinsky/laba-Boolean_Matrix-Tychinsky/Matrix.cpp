#include <iostream>
#include "assert.h"
#include "Matrix.h"

//конструкторы и деструктор
BoolMatrix::BoolMatrix() {}

BoolMatrix::BoolMatrix(const int cols, const int rows) : m_cols(cols), m_rows(rows) {
	assert(cols >= 0 && rows >= 0);
	m_vectors = new BoolVector[m_rows];
	for (int i = 0; i < m_rows; i++)
		m_vectors[i] = BoolVector(m_cols);
}

BoolMatrix::BoolMatrix(const int cols, const int rows, const bool value) : m_cols(cols), m_rows(rows) {
	m_vectors = new BoolVector[m_rows];
	for (int i = 0; i < m_rows; i++)
		m_vectors[i] = BoolVector(m_cols, value);
}

BoolMatrix::BoolMatrix(const char** matrix, const int cols, const int rows) : m_cols(cols), m_rows(rows) {
	m_vectors = new BoolVector[m_rows];
	for (int i = 0; i < m_rows; i++) 
		m_vectors[i] = BoolVector(matrix[i], cols);
}

BoolMatrix::BoolMatrix(const BoolMatrix& other) : m_cols(other.m_cols), m_rows(other.m_rows) {
	m_vectors = new BoolVector[m_rows];
	for (int i = 0; i < m_rows; i++)
		m_vectors[i] = other.m_vectors[i];
}

BoolMatrix::~BoolMatrix() {
	delete[] m_vectors;
}

//кол-во строк и столбцов и обмен матриц
int BoolMatrix :: AmountOfRows() const {
	return m_rows;
}

int BoolMatrix::AmountOfCols() const {
	return m_cols;
}

void BoolMatrix::Swap(BoolMatrix& other) {
	using std::swap;
	swap(m_cols, other.m_cols);
	swap(m_rows, other.m_rows);
	swap(m_vectors, other.m_vectors);
}

//ввод и вывод
void BoolMatrix::Print() const {
	for (int i = 0; i < m_rows; i++) 
		m_vectors[i].Print();
	std::cout << std::endl;
}

void BoolMatrix::Scan() {
	for (int i = 0; i < m_rows; i++)
		m_vectors[i].Scan();
}

//конъюкция и дизъюнкция всех строк
BoolVector BoolMatrix::ConjunctionOfRows() {
	BoolVector back(m_vectors[0]);
	for (int i = 1; i < m_rows; i++) 
		back &= m_vectors[i];
	return back;
}

BoolVector BoolMatrix::DisjunctionOfRows() {
	BoolVector back(m_vectors[0]);
	for (int i = 1; i < m_rows; i++)
		back |= m_vectors[i];
	return back;
}

//вес матрицы и строки
int BoolMatrix::Weight() const {
	int weight = 0;
	for (int i = 0; i < m_cols; i++)
		weight += m_vectors[i].WeightVector();
	return weight;
}

int BoolMatrix::Weight(const int row) const {
	assert(row >= 0 && row < m_rows);
	return m_vectors[row].WeightVector();
}

//инверсии
void BoolMatrix::Inversion(const int col, const int row) {
	assert(col >= 0 && col < m_cols && row < m_rows && row >= 0);
	m_vectors[row].Inversion(col);
}

void BoolMatrix::Inversion(const int from, const int row, const int to) {
	assert(row >= 0 && row < m_rows);
	for (int i = from; i <= to; i++)
		m_vectors[row].Inversion(i);
}

//вставки битов
void BoolMatrix::Set(const bool value, const int col, const int row) {
	assert(row >= 0 && row < m_rows);
	m_vectors[row].Set(value, col);
}

void BoolMatrix::Set(const bool value, const int from, const int row, const int to) {
	assert(row >= 0 && row < m_rows);
	m_vectors[row].Set(value, from, to);
}

//перегрузки

//потоковый ввод и вывод
