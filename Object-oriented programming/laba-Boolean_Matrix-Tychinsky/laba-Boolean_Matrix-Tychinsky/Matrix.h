﻿#pragma once
#include "../../laba-Boolean_vector-Tychinsky/laba-Boolean_vector-Tychinsky/Vector.h"

class BoolMatrix {
public:
	BoolMatrix() = default;
	BoolMatrix(const int cols, const int rows, const bool value);
	BoolMatrix( char** matrix, const int cols, const int rows);
	BoolMatrix(const BoolMatrix& other);
	~BoolMatrix();

	int AmountOfRows() const;
	int AmountOfCols() const;

	void Swap(BoolMatrix& other);

	void Print() const;
	void Scan();

	BoolVector ConjunctionOfRows() const;
	BoolVector DisjunctionOfRows() const;

	int Weight() const;
	int Weight(const int row) const;

	void Inversion(const int col, const int row);
	void Inversion(const int from, const int row, const int to);

	void Set(const bool value, const int col, const int row);
	void Set(const bool value, const int index_i, const int index_j, const int k);

	BoolMatrix& operator = (const BoolMatrix& other);
	BoolVector& operator [] (const int index);
	const BoolVector& operator [] (const int index) const;
	BoolMatrix operator & (const BoolMatrix& other) const;
	BoolMatrix& operator &= (const BoolMatrix& other);
	BoolMatrix operator | (const BoolMatrix& other) const;
	BoolMatrix& operator |= (const BoolMatrix& other);
	BoolMatrix operator ^ (const BoolMatrix& other) const;
	BoolMatrix& operator ^= (const BoolMatrix& other);
	BoolMatrix operator ~ () const;

private:
	BoolVector* m_vectors = nullptr;
	int m_rows = 0;
	int	m_cols = 0;
};

std::ostream& operator << (std::ostream& stream, const BoolMatrix& bm);
std::istream& operator >> (std::istream& stream, BoolMatrix& bm);