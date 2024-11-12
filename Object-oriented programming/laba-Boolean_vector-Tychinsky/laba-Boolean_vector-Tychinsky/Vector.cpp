#include <iostream>
#include <vector>
#include <cstring>
#include "assert.h"
#include "Vector.h"

using std::cin;
using std::cout;
using std::endl;
using std::swap;
using std::string;

//конструкторы - деструктор
BoolVector::BoolVector():BoolVector(cell_size,0) {

}
BoolVector::BoolVector(const int length, const bool value) : m_length(length){
	m_cell_count = m_length / 8 + (m_length % 8 == 0 ? 0 : 1);
	
	m_cells = new UC[m_cell_count];

	value ? Set(1) : Set(0);
}
BoolVector::BoolVector(const char* array) : BoolVector(strlen(array),0) {
	for (int i = 0; i < m_length; i++) 
		if (array[i] == '1')
			Set(1, i);
}
BoolVector::BoolVector(const BoolVector& other):m_cell_count(other.m_cell_count), m_length(other.m_length) {
	m_cells = new UC[m_cell_count];
	for (int i = 0; i < m_cell_count; i++)
		m_cells[i] = other.m_cells[i];
}
BoolVector::~BoolVector() {
    delete[] m_cells;
}

int BoolVector::CountOfBit() {
	return m_length;
}

void BoolVector::SwapVectors(BoolVector& other) {
	swap(m_length, other.m_length);
	swap(m_cell_count, other.m_cell_count);
	swap(m_cells, other.m_cells);
}

void BoolVector::Scan() {
	string entering;

	cout << endl << "Введите булев вектор: ";
	cin >> entering;

	m_length = entering.length();

	for (int i = 0; i < m_length; i++) {
		assert(entering[i] == '0' || entering[i] == '1');

		entering[i] == '1' ? Set(1, i) : Set(0, i);
	}
}
void BoolVector::Print() const {
	cout << "[ ";
	for (int j = 0; j < m_cell_count; j++) {
		for (int i = 1 << 7; i > 0; i >>= 1) {
			m_cells[j] & i ? cout << "1" : cout << "0";

			if ((i >> 1) > 0)
				cout << " ";
		}
	}
	cout << "] " << endl;
}

void BoolVector::Inversion() {
	for (int i = 0; i < m_cell_count; i++)
		m_cells[i] = ~m_cells[i];
}
void BoolVector::Inversion(int index) {
	m_cells[index] = ~m_cells[index];
}

void BoolVector::Set(const bool value, const int index) {
	assert(index < m_length && index >= 0);
	for (int i = index; i < m_cell_count; i++) 
		value ? m_cells[i] = (m_cells[i] & 0) | 1 : m_cells[i] &= 0;
}
void BoolVector::Set(const bool value, const int index, const int component_count) {
	assert(index < m_length && index >= 0);
	for (int i = index; i - index < component_count; i++) 
		value ? m_cells[i] = (m_cells[i] & 0) | 1 : m_cells[i] &= 0;
}
void BoolVector::Set(const bool value) {
	for (int i = 0; i < m_cell_count; i++) 
		value ? m_cells[i] = (m_cells[i] & 0) | 1 : m_cells[i] &= 0;
}

int BoolVector::WeightVector() const{
	int weight = 0;

	for (int i = 0; i < m_cell_count; i++) 
		for (int mask = 1 << 7; mask > 0; mask >>= 1) 
			if (m_cells[i] & mask)
				weight++;

	return weight;
}

BoolVector& BoolVector::operator [] (const int index) {
	assert(index >= 0 && index < m_length);


	//надо сделать!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



	return *this;
}

BoolVector& BoolVector::operator & (const BoolVector& other) {
	assert(m_length == other.m_length);

	BoolVector back(*this);

	for (int i = 0; i < m_cell_count; i++) 
		back.m_cells[i] = m_cells[i] & other.m_cells[i];

	return back;
}
BoolVector& BoolVector::operator &= (const BoolVector& other) {
	return *this = *this & other;
}
BoolVector& BoolVector:: operator | (const BoolVector& other) {
	assert(m_length == other.m_length);

	BoolVector back(*this);

	for (int i = 0; i < m_cell_count; i++)
		back.m_cells[i] = m_cells[i] | other.m_cells[i];

	return back;
}
BoolVector& BoolVector::operator |= (const BoolVector& other) {
	return *this = *this | other;
}
BoolVector& BoolVector::operator ^ (const BoolVector& other) {
	assert(m_length == other.m_length);

	BoolVector back(*this);

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

	for (int i = 0; i < m_cell_count; i++)
		m_cells[i] <<= value;
	
	return *this;
}
BoolVector& BoolVector::operator >>= (const int value) {
	assert(value >= 0);

	for (int i = 0; i < m_cell_count; i++)
		m_cells[i] >>= value;

	return *this;
}
BoolVector& BoolVector::operator ~ () {
	BoolVector back(*this);

	back.Inversion();

	return back;
}
BoolVector& BoolVector::operator = (const BoolVector& other) {
	if (this == &other)
		return *this;

	m_cell_count = other.m_cell_count;
	m_length = other.m_length;

	delete[] m_cells;
	m_cells = new UC[m_cell_count];

	for (int i = 0; i < m_cell_count; i++)
		m_cells[i] = other.m_cells[i];
	
	return *this;
}

bool BoolVector::operator == (const BoolVector& other) {
	if (m_length != other.m_length)
		return false;

	for (int i = 0; i < m_cell_count; i++)
		if (m_cells[i] != other.m_cells[i]) 
			return false;
		
	return true;
}

//BoolRank
