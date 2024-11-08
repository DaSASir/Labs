#include <iostream>
#include <vector>
#include <cstring>
#include "Vector.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;

//конструкторы - деструктор
BoolVector::BoolVector() {
    
}
BoolVector::BoolVector(const int length, const bool value) : m_length(length){
	
}
BoolVector::BoolVector(const UC* array) {

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

}

void BoolVector::SwapVectors(BoolVector& other) {

}

void BoolVector::Scan() {

}
void BoolVector::Print() {

}

void BoolVector::Inversion() {

}
void BoolVector::Inversion(int index) {

}

void BoolVector::Set0(int index) {

}
void BoolVector::Set0(int index, int component_count) {

}
void BoolVector::Set0() {

}
void BoolVector::Set1(int index) {

}
void BoolVector::Set1(int index, int component_count) {

}
void BoolVector::Set1() {

}

int BoolVector::WeightVector() {

}


BoolVector& BoolVector::operator & (BoolVector& other) {

}
BoolVector& BoolVector::operator &= (BoolVector& other) {

}
BoolVector& BoolVector:: operator | (BoolVector& other) {

}
BoolVector& BoolVector::operator |= (BoolVector& other) {

}
BoolVector& BoolVector::operator ^ (BoolVector& other) {

}
BoolVector& BoolVector::operator ^= (BoolVector& other) {

}
BoolVector& BoolVector::operator << (int value) {

}
BoolVector& BoolVector::operator >> (int value) {

}
BoolVector& BoolVector::operator <<= (int value) {

}
BoolVector& BoolVector::operator >>= (int value) {

}
BoolVector& BoolVector::operator ~ () {

}
BoolVector& BoolVector::operator = (BoolVector& other) {

}

bool BoolVector::operator == (BoolVector& other) {

}
bool BoolVector::operator != (BoolVector& other) {

}