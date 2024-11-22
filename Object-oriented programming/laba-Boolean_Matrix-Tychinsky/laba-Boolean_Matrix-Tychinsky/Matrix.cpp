#include <iostream>
#include "assert.h"
#include "Matrix.h"

BoolMatrix::BoolMatrix():BoolMatrix(1,8,0) {
}
BoolMatrix::BoolMatrix(const UI col_count, const UI row_count, const bool value)
	:m_amount_col(col_count), m_amount_row(row_count) {

	m_count_vectors = new BoolVector[m_amount_row];

	BoolVector vector(m_amount_col, value);

	for (int i = 0; i < m_amount_row; i++)
		m_count_vectors[i] = vector;

}
BoolMatrix::BoolMatrix(const char** matrix, const UI col_count, const UI row_count)
	:m_amount_col(col_count), m_amount_row(row_count) {

	m_count_vectors = new BoolVector[m_amount_row];

	for (int i = 0; i < m_amount_row; i++)
		m_count_vectors[i] = matrix[i];
}
BoolMatrix::BoolMatrix(const BoolMatrix& other)
	:m_amount_col(other.m_amount_col), m_amount_row(other.m_amount_row) {

	m_count_vectors = new BoolVector[m_amount_row];

	for (int i = 0; i < m_amount_row; i++)
		m_count_vectors[i] = other.m_count_vectors[i];
}

BoolMatrix::~BoolMatrix() {
	delete[] m_count_vectors;
}

int BoolMatrix::GetAmountOfRows() {
	return m_amount_row;
}
int BoolMatrix::GetAmountOfCols() {
	return m_amount_col;
}

void BoolMatrix::Swap(BoolMatrix& other) {
	using std::swap;
	swap(m_amount_col, other.m_amount_col);
	swap(m_amount_row, other.m_amount_row);
	swap(m_count_vectors, other.m_count_vectors);
}

void BoolMatrix::Print() {
	for (int i = 0; i < m_amount_row; i++) 
		m_count_vectors[i].Print();
}
int BoolMatrix::Weight() {
	int weight = 0;
	for(int i =0 ; i < m_amount_row; i ++)
		weight += m_count_vectors[i].WeightVector();
	return weight;
}
//���������� ���� ����� (���������� ����� ������);

//���������� ���� ����� (���������� ����� ������);

int BoolMatrix::Weight(const UI index_row) {
	return m_count_vectors[index_row].WeightVector();
}
void BoolMatrix::Inversion(const int index_i, const int index_j) {
	m_count_vectors[index_j].Inversion(index_i);
}
void BoolMatrix::Inversion(const int index_i, const int index_j, const int k) {
	assert(index_i + k < m_amount_col);
	for(int i = 0; i < k; i++)
		m_count_vectors[index_j].Inversion(index_i);
}
void BoolMatrix::Set(const bool value, const int index_i, const int index_j) {
	m_count_vectors[index_j].Set(value, index_i);
}
void BoolMatrix::Set(const bool value, const int index_i, const int index_j, const int k) {
	assert(index_i + k < m_amount_col);
	for (int i = 0; i < k; i++)
		m_count_vectors[index_j].Set(value, index_i);
}

