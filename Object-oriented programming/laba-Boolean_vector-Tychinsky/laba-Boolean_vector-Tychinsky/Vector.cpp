#include <iostream>
#include <cstring>
#include "assert.h"
#include "Vector.h"

//конструкторы и деструктор
BoolVector::BoolVector() {}

BoolVector::BoolVector(const int size) : m_length(size) {
	m_cell_count = m_length / CellSize;
	if (m_length % CellSize != 0)
		m_cell_count++;
	m_cells = new Cell[m_cell_count];
}

BoolVector::BoolVector(const int length, const bool value) : m_length(length) {
	m_cell_count = m_length / CellSize;
	if (m_length % CellSize != 0)
		m_cell_count++;
	m_cells = new Cell[m_cell_count];

	Set(value ? 1 : 0);
}

BoolVector::BoolVector(const char* array, const int size) : m_length(size) {
	assert(size >= 0);
	m_cell_count = m_length / CellSize;
	if (m_length % CellSize != 0)
		m_cell_count++;
	m_cells = new Cell[m_cell_count];
	
	for (int i = 0; i < size; i++)
		Set(array[i] == '1' ? 1 : 0, i);
}

BoolVector::BoolVector(const BoolVector& other) : m_length(other.m_length), m_cell_count(other.m_cell_count) {
	m_cells = new Cell[m_cell_count];

	for (int i = 0; i < m_cell_count; i++)
		m_cells[i] = other.m_cells[i];
}

BoolVector::~BoolVector() {
	delete[] m_cells;
}

//ввод и вывод
void BoolVector::Print() const {
	using std::cout;
	cout << "[ ";
	for (int i = 0; i < m_length; i++)
		cout << BitValue(i) << " ";

	cout << "]\n";
}

void BoolVector::Scan() {
	using std::cout;
	using std::cin;

	cout << "\nВведите булев вектор длины = " << m_length << ":\n";
	char* string = new char[m_length];
	for (int i = 0; i < m_length; i++)
		cin >> string[i];

	for (int i = 0; i < m_length; i++)
		Set(string[i] == '1' ? 1 : 0, i);

	delete[] string;
}

//получения кол-во битов (длины) вектора, кол-ва ячеек, значение бита и веса вектора (кол-во 1)
int BoolVector::CountOfBit() const {
	return m_length;
}

int BoolVector::CountOfCell() const {
	return m_cell_count;
}

bool BoolVector::BitValue(const int index) const {
	assert(index >= 0 && index < m_length);
	return m_cells[index / CellSize] & _mask(index);
}

int BoolVector::WeightVector() const {
	int weight = 0;
	for (int i = 0; i < m_cell_count; i++)
		for (int bit = 0; bit < CellSize; bit++)
			if (m_cells[i] & _mask(bit))
				weight++;
	
	return weight;
}

//обмен векторов и инверсии
void BoolVector::SwapVectors(BoolVector& other) {
	using std::swap;
	swap(m_length, other.m_length);
	swap(m_cell_count, other.m_cell_count);
	swap(m_cells, other.m_cells);
}

void BoolVector::Inversion() {
	for (int i = 0; i < m_cell_count; i++)
		m_cells[i] = ~m_cells[i];
}

void BoolVector::Inversion(const int index) {
	Set(!BitValue(index), index);
}

//вставка битов
void BoolVector::Set(const bool value) {
	for (int i = 0; i < m_cell_count; i++)
		m_cells[i] = (!value) ? 0 : ~0;
}

void BoolVector::Set(const bool value, const int index) {
	assert(index >= 0 && index < m_length);
	if (value)
		m_cells[index / CellSize] |= _mask(index);
	else
		m_cells[index / CellSize] &= ~_mask(index);
}

void BoolVector::Set(const bool value, const int index, const int component_count) {
	for (int i = 0; i < component_count; i++) 
		Set(index + i, value);
}

//маска
BoolVector::Cell BoolVector::_mask(const int index) {
	return (1 << CellSize - 1 - (index % CellSize));
}

//перегрузки
BoolVector::BoolRank BoolVector::operator [] (const int index) {
	assert(index >= 0 && index < m_length);
	return BoolRank(&m_cells[index / CellSize], _mask(index));
}

BoolVector BoolVector::operator & (const BoolVector& other) const {
	assert(m_length == other.m_length);
	BoolVector back(*this);

	for (int i = 0; i < m_cell_count; i++) 
		back.m_cells[i] = m_cells[i] & other.m_cells[i];

	return back;
}

BoolVector& BoolVector::operator &= (const BoolVector& other) {
	*this = *this & other;
	return *this;
}

BoolVector BoolVector::operator | (const BoolVector& other) const {
	assert(m_length == other.m_length);
	BoolVector back(*this);

	for (int i = 0; i < m_cell_count; i++)
		back.m_cells[i] = m_cells[i] | other.m_cells[i];

	return back;
}

BoolVector& BoolVector::operator |= (const BoolVector& other) {
	*this = *this | other;
	return *this;
}

BoolVector BoolVector::operator ^ (const BoolVector& other) const {
	assert(m_length == other.m_length);
	BoolVector back(*this);

	for (int i = 0; i < m_cell_count; i++)
		back.m_cells[i] = m_cells[i] ^ other.m_cells[i];

	return back;
}

BoolVector& BoolVector::operator ^= (const BoolVector& other) {
	*this = *this ^ other;
	return *this;
}

BoolVector BoolVector::operator << (const int value) const {
	BoolVector back(*this);
	back <<= value;
	return back;
}

BoolVector BoolVector::operator >> (const int value) const {
	BoolVector back(*this);
	back >>= value;
	return back;
}

BoolVector& BoolVector::operator <<= (const int value) {
	assert(value > 0);

	if (value >= m_length) Set(0);
	else {
		for (int i = 0; i < m_length - value; i++)
			Set(BitValue(i), i + value);
		for (int i = m_length - value; i < m_length; i++)
			Set(0, i);
	}

	return *this;
}

BoolVector& BoolVector::operator >>= (const int value) {
	assert(value > 0);

	if (value >= m_length) Set(0);
	else {
		for (int i = m_length - 1; i > value; i--)
			Set(BitValue(i), i - value);
		for (int i = value - 1; i >= 0; i--)
			Set(0, i);
	}

	return *this;
}

BoolVector BoolVector::operator ~ () const {
	BoolVector back(*this);
	back.Inversion();
	return back;
}

BoolVector& BoolVector::operator = (const BoolVector& other) {
	assert(*this != other);

	m_length = other.m_length;
	m_cell_count = other.m_cell_count;

	delete[] m_cells;
	m_cells = new Cell[m_cell_count];

	for (int i = 0; i < m_cell_count; i++)
		m_cells[i] = other.m_cells[i];
	
	return *this;
}

bool BoolVector::operator == (const BoolVector& other) const {
	if (m_length != other.m_length) return false;

	for (int i = 0; i < m_cell_count; ++i)
		if (m_cells[i] != other.m_cells[i]) 
			return false;
		
	return true;
}

bool BoolVector::operator != (const BoolVector& other) const {
	return !(*this == other);
}

//BoolRank
BoolVector::BoolRank::BoolRank(Cell* cell, Cell mask) : m_cell(cell), m_mask(mask) {
	assert(m_cell != nullptr);
	assert(m_mask > 0);
}

BoolVector::BoolRank& BoolVector::BoolRank::operator=(const BoolVector::BoolRank& other) {
	return operator=(static_cast<bool>(other));
}

BoolVector::BoolRank& BoolVector::BoolRank::operator=(const bool value) {
	if (value)
		*m_cell |= m_mask;
	else
		*m_cell &= ~m_mask;
	return *this;
}

BoolVector::BoolRank::operator bool() const {
	return (*m_cell & m_mask) != 0;
}

//потоковый ввод и вывод
std::ostream& operator<<(std::ostream& stream, const BoolVector& bv) {
	stream << "[ ";
	for (int i = 0; i < bv.CountOfBit(); i++)
		stream << bv.BitValue(i) << " ";

	stream << "]\n";
	return stream;
}

std::istream& operator>>(std::istream& stream, BoolVector& bv) {
	char* string = new char[bv.CountOfBit()];
	for (int i = 0; i < bv.CountOfBit(); i++)
		stream >> string[i];

	for (int i = 0; i < bv.CountOfBit(); i++)
		bv.Set((string[i] == '1') ? 1 : 0, i);

	delete[] string;
	return stream;
}