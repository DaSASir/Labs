#include <iostream>
#include <vector>
#include <cstring>
#include "assert.h"
#include "Vector.h"

//конструкторы - деструктор
BoolVector::BoolVector(){}

BoolVector::BoolVector(const int length, const bool value) : m_length(length) {
	m_cell_count = (length + cell_size - 1) / cell_size;
	m_cells = new bool[m_cell_count];
	value ? Set(1) : Set(0);
}
BoolVector::BoolVector(const char* array) : BoolVector(strlen(array), 0) {
	for (int i = 0; i < m_length; i++)
		Set(array[i] == '0', i);
}
BoolVector::BoolVector(const BoolVector& other) 
	:m_length(other.m_length), m_cell_count(other.m_cell_count) {
	m_cells = new bool[m_cell_count];
	for (int i = 0; i < m_cell_count; i++)
		m_cells[i] = other.m_cells[i];
}
BoolVector::~BoolVector() {
	delete[] m_cells;
}

int BoolVector::CountOfBit() const{
	return m_length;
}

void BoolVector::SwapVectors(BoolVector& other) {
	using std::swap;
	swap(m_length, other.m_length);
	swap(m_cell_count, other.m_cell_count);
	swap(m_cells, other.m_cells);
}

void BoolVector::Scan() {
	using std::cout;
	using std::cin;

	delete[]m_cells;
	cout << "Введите длину вектора: ";
	cin >> m_length;

	m_cell_count = (m_length + cell_size - 1) / cell_size;
	m_cells = new bool[m_length];

	cout << "Введите биты:\n";
	for (int i = 0; i < m_length; i++) {
		int bit;
		cin >> bit;
		assert(bit == 0 || bit == 1);
		Set(bit, i);
	}
}
void BoolVector::Print() const {
	using std::cout;
	cout << "[ ";
	for (int i = 0; i < m_length; i++)
		cout << (m_cells[i] ? "1 " : "0 ");
	
	cout << "]\n";
}

void BoolVector::Inversion() {
	for (int i = 0; i < m_length; i++)
		Inversion(i);
}
void BoolVector::Inversion(int index) {
	assert(index >= 0 && index < m_length);
	m_cells[index] = m_cells[index] ? 0 : 1;
}

void BoolVector::Set(const bool value, const int index) {
	assert(index < m_length && index >= 0);
	m_cells[index] = value;
}
void BoolVector::Set(const bool value, const int index, const int component_count) {
	assert(index + component_count < m_length && index >= 0);
	for (int i = 0; i < component_count; i++)
		Set(value, i + index);
}
void BoolVector::Set(const bool value) {
	for (int i = 0; i < m_length; i++)
		Set(value, i);
}

int BoolVector::WeightVector() const {
	int weight = 0;

	for (int i = 0; i < m_length; i++)
		if (m_cells[i]) weight++;

	return weight;
}

BoolVector::BoolRank BoolVector::operator [] (const int index) {
	assert(index >= 0 && index < m_length);
	return BoolRank(m_cells[index], index);
}

BoolVector& BoolVector::operator & (const BoolVector& other) {
	assert(m_length == other.m_length);

	BoolVector back(m_length,0);

	for (int i = 0; i < m_length; i++)
		back.m_cells[i] = m_cells[i] & other.m_cells[i];

	return back;
}
BoolVector& BoolVector::operator &= (const BoolVector& other) {
	return *this = *this & other;
}
BoolVector& BoolVector:: operator | (const BoolVector& other) {
	assert(m_length == other.m_length);

	BoolVector back(m_length, 0);

	for (int i = 0; i < m_cell_count; i++)
		back.m_cells[i] = m_cells[i] | other.m_cells[i];

	return back;
}
BoolVector& BoolVector::operator |= (const BoolVector& other) {
	return *this = *this | other;
}
BoolVector& BoolVector::operator ^ (const BoolVector& other) {
	assert(m_length == other.m_length);

	BoolVector back(m_length, 0);

	for (int i = 0; i < m_cell_count; i++)
		back.m_cells[i] = m_cells[i] ^ other.m_cells[i];

	return back;
}
BoolVector& BoolVector::operator ^= (const BoolVector& other) {
	return *this = *this ^ other;
}
BoolVector& BoolVector::operator << (const int value) {
	BoolVector back(*this);
	return back <<= value;
}
BoolVector& BoolVector::operator >> (const int value) {
	BoolVector back(*this);
	return back >>= value;
}
BoolVector& BoolVector::operator <<= (const int value) {
	assert(value >= 0);

	for (int i = 0; i < m_length - value; i++)
		m_cells[i] = m_cells[i + value];

	for (int i = m_length - value; i < m_length; i++)
		m_cells[i] = 0;

	return *this;
}
BoolVector& BoolVector::operator >>= (const int value) {
	assert(value >= 0);

	for (int i = m_length - 1; i >= value; i--)
		m_cells[i] = m_cells[i - value];

	for (int i = 0; i < value; i++)
		m_cells[i] = 0;

	return *this;
}
BoolVector& BoolVector::operator ~ () {
	Inversion();
	return *this;
}
BoolVector& BoolVector::operator = (const BoolVector& other) {
	if (this == &other)
		return *this;

	m_cell_count = other.m_cell_count;
	m_length = other.m_length;

	delete[] m_cells;
	m_cells = new bool[m_cell_count];

	for (int i = 0; i < m_cell_count; i++)
		m_cells[i] = other.m_cells[i];

	return *this;
}

bool BoolVector::operator == (const BoolVector& other) const{
	if (m_length != other.m_length)
		return false;

	for (int i = 0; i < m_cell_count; i++)
		if (m_cells[i] != other.m_cells[i])
			return false;

	return true;
}

//BoolRank
BoolVector::BoolRank::BoolRank(bool& cell, const int index) 
	: m_cell(cell), m_index(index){}

BoolVector::BoolRank& BoolVector::BoolRank::operator = (const bool value) {
	value ? m_cell |= (1 << m_index) : m_cell &= ~(1 << m_index);
	return *this;
}

BoolVector::BoolRank& BoolVector::BoolRank:: operator = (const BoolRank& other) {
	return *this = other;
}

BoolVector::BoolRank& BoolVector::BoolRank:: operator |= (const bool value) {
	if (value)
		m_cell |= (1 << m_index);
	return *this;
}

BoolVector::BoolRank& BoolVector::BoolRank:: operator &= (const bool value) {
	if (!value)
		m_cell &= ~(1 << m_index);
	return *this;
}

BoolVector::BoolRank& BoolVector::BoolRank:: operator ^= (const bool value) {
	if (value)
		m_cell ^= (1 << m_index);
	return *this;
}

BoolVector::BoolRank& BoolVector::BoolRank:: operator ~ () {
	m_cell ^= (1 << m_index);
	return *this;
}

bool BoolVector::BoolRank::operator == (const bool value) const {
	return *this == value;
}
bool BoolVector::BoolRank::operator != (const bool value) const {
	return *this != value;
}