#include <iostream>
#include <vector>
#include "Array.h"

//iterator
Array::Array():m_array(nullptr) {
}
Array::Array(const char* array) {

}
Array::Array(const Array& other):m_size(other.m_size) {

}
Array::~Array() {
	delete[] m_array;
}

int Array::GetSize() {
	return m_size;
}

void Array::Swap(Array& other) {

}

int Array::FindElement(const int value) {

}

void Array::Print() const {

}
void Array::Scan() {

}

void Array::Sorting() {

}

void Array::InsertingByIndex(const int index) {

}

void Array::DeleteByIndex(const int index) {

}
void Array::DeleteByValue(const int value) {

}
void Array::DeleteAllByValue(const int value) {

}

int Array::Min() const {

}
int Array::Max() const {

}

Iterator Array::begin() {

}
Iterator Array::end() {

}

void Array::InsertingByIterator() {

}

void Array::DeleteByIterator() {

}



Array Array:: operator[] (const int index) {

}
Array Array::operator = (const Array& other) {

}
Array Array::operator + (const int value) {

}
Array Array::operator += (const int value) {

}
Array Array::operator + (const Array& otrher) {

}
Array Array::operator += (const Array& otrher) {

}
bool Array::operator == (const Array& other) {

}
bool Array::operator != (const Array& other) {

}


//Iterator
Iterator::Iterator(int* object) {
	m_cell = object;
}

int& Iterator::operator*() {

}
const int& Iterator::operator*() const {

}

int Iterator::operator++() {

}
int Iterator::operator--() {

}

int Iterator::operator++(int) {

}
int Iterator::operator--(int) {

}

bool Iterator::operator==(const int& other) const {

}
bool Iterator::operator!=(const int& other) const {

}