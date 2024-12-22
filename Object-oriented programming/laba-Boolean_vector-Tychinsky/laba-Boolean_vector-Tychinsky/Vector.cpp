#include <iostream>
#include <vector>
#include <cstring>
#include "assert.h"
#include "Vector.h"

//конструкторы
BoolVector::BoolVector() : BoolVector(CellSize,0) {}

BoolVector::BoolVector(const int length, const bool value) : m_length(length) {
	m_cell_count = m_length / CellSize;
	if (m_length % CellSize != 0)
		m_cell_count++;

	m_cells = new Cell[m_cell_count];
	value ? Set(1) : Set(0);
}

BoolVector::BoolVector(const char* array, const int size_a) : BoolVector(size_a, 0) {
	for (int i = 0; i < m_length; i++)
		if(array[i] == '1')
			Set(1, i);
}

BoolVector::BoolVector(const BoolVector& other) 
	:m_length(other.m_length), m_cell_count(other.m_cell_count) {
	m_cells = new Cell[m_cell_count];
	for (int i = 0; i < m_cell_count; i++)
		m_cells[i] = other.m_cells[i];
}

BoolVector::~BoolVector() {
	delete[] m_cells;
}

//вывод значений
int BoolVector::CountOfBit() const {
	return m_length;
}

int BoolVector::CountOfCell() const {
	return m_cell_count;
}

bool BoolVector::BitValue(int index) const {
	assert(index >= 0 && index < m_length);
	return m_cells[index / CellSize] & _mask(index);
}
int BoolVector::WeightVector() const {
	int weight = 0;
	for (int i = 0; i < m_cell_count; i++)
		for (int j = 0; j < CellSize; j++)
			if (m_cells[i] & (1 << j))
				weight++;
	
	return weight;
}

//обмен
void BoolVector::SwapVectors(BoolVector& other) {
	using std::swap;
	swap(m_length, other.m_length);
	swap(m_cell_count, other.m_cell_count);
	swap(m_cells, other.m_cells);
}

//ввод, вывод
void BoolVector::Scan() {
	std::cin >> *this;
}

void BoolVector::Print() const {
	std::cout << *this;
}

//инверсия битов
void BoolVector::Inversion() {
	for (int i = 0; i < m_cell_count; i++)
		Inversion(i);
}

void BoolVector::Inversion(const int index) {
	assert(index >= 0 && index < m_length);
	Set(!BitValue(index), index);
}

//вставка битов
void BoolVector::Set(const bool value, const int index) {
	assert(index >= 0 && index < m_length);
	value ? m_cells[index / CellSize] |= _mask(index) : m_cells[index / CellSize] &= ~_mask(index);
}

void BoolVector::Set(const bool value, const int index, const int component_count) {
	assert(index + component_count <= m_length && index >= 0);
	for (int i = index; i < index + component_count; i++)
		Set(value, i);
}

void BoolVector::Set(const bool value) {
	for (int i = 0; i < m_cell_count; i++)
		Set(value, i);
}

//перегрузки
BoolVector::BoolRank BoolVector::operator [] (const int index) {
	assert(index >= 0 && index < m_length);
	return BoolRank(&m_cells[index / CellSize], _mask(index));
}

BoolVector BoolVector::operator & (const BoolVector& other) {
	assert(m_length == other.m_length);

	BoolVector back(m_length);
	for (int i = 0; i < m_cell_count; i++)
		back.m_cells[i] = m_cells[i] & other.m_cells[i];
	
	return back;
}

BoolVector& BoolVector::operator &= (const BoolVector& other) {
	*this = *this & other;
	return *this;
}
BoolVector BoolVector::operator | (const BoolVector& other) {
	assert(m_length == other.m_length);

	BoolVector back(m_length);
	for (int i = 0; i < m_cell_count; i++)
		back.m_cells[i] = m_cells[i] | other.m_cells[i];

	return back;
}

BoolVector& BoolVector::operator |= (const BoolVector& other) {
	*this = *this | other;
	return *this;
}

BoolVector BoolVector::operator ^ (const BoolVector& other) {
	assert(m_length == other.m_length);

	BoolVector back(m_length);
	for (int i = 0; i < m_cell_count; i++)
		back.m_cells[i] = m_cells[i] ^ other.m_cells[i];

	return back;
}

BoolVector& BoolVector::operator ^= (const BoolVector& other) {
	*this = *this ^ other;
	return *this;
}

BoolVector BoolVector::operator << (const int value) {
	assert(value >= 0);

	BoolVector back(m_length);
	if(value >= m_length)
		return back;

	for (int i = 0; i < m_length - value; i++) 
		back.Set(BitValue(i), i + value);
	
	return back;
}

BoolVector BoolVector::operator >> (const int value) {
	assert(value >= 0);

	BoolVector back(m_length);
	if (value >= m_length)
		return back;

	for (int i = 0; i < m_length - value; i++)
		back.Set(BitValue(i + value), i);
	
	return back;
}

BoolVector& BoolVector::operator <<= (const int value) {
	assert(value >= 0);
	*this = *this << value;
	return *this;
}

BoolVector& BoolVector::operator >>= (const int value) {
	assert(value >= 0);
	*this = *this >> value;
	return *this;
}

BoolVector BoolVector::operator ~ () const{
	BoolVector back(m_length);
	for (int i = 0; i < m_cell_count; i++)
		back.m_cells[i] = ~m_cells[i];
	
	return back;
}

BoolVector& BoolVector::operator = (const BoolVector& other) {
	if (!(*this == other)) {
		m_length = other.m_length;
		m_cell_count = other.m_cell_count;

		delete[] m_cells;
		m_cells = new Cell[m_cell_count];
		for (int i = 0; i < m_cell_count; i++)
			m_cells[i] = other.m_cells[i];
	}
	return *this;
}

bool BoolVector::operator == (const BoolVector& other) const {
	if (m_length != other.m_length)
		return false;

	for (int i = 0; i < m_cell_count; i++)
		if (m_cells[i] != other.m_cells[i]) 
			return false;
		
	return true;
}

//private
BoolVector::Cell BoolVector::_mask(int index) {
	return (1 << (CellSize - 1 - (index % CellSize)));
}

//BoolRank
BoolVector::BoolRank::BoolRank(Cell* cell, Cell mask) : m_cell(cell), m_mask(mask) {
	assert(m_cell != nullptr && mask > 0);
}

BoolVector::BoolRank& BoolVector::BoolRank::operator=(const BoolRank& other) {
	return operator=(static_cast<bool>(other));
}

BoolVector::BoolRank& BoolVector::BoolRank::operator=(bool value) {
	value ? *m_cell |= m_mask : *m_cell &= ~m_mask;
	return *this;
}

BoolVector::BoolRank::operator bool() const {
	return (*m_cell & m_mask) != 0;
}

//потоковый ввод, вывод
std::ostream& operator<<(std::ostream& stream, const BoolVector& bv) {
	for (int i = 0; i < bv.CountOfBit(); i++) 
		stream << bv.BitValue(i) ? "1 " : "0 ";

	return stream;
}

std::istream& operator>>(std::istream& stream, BoolVector& bv) {
	std::string st;
	stream >> st;

	while (st.size() < bv.CountOfBit())
		stream >> st;

	for (int i = 0; i < bv.CountOfBit(); i++) 
		st[i] == '1' ? bv.Set(1, i) : bv.Set(0, i);

	return stream;
}