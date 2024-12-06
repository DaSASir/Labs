#include <iostream>
#include <assert.h>
#include "Array.h"

//Array
template <typename T>
Array<T>::Array() : m_data(nullptr) {}

template <typename T>
Array<T>::Array(const T* array, const int size): m_size(size) {
	m_data = new T[m_size];
	for (int i = 0; i < size; i++)
		m_data[i] = array[i];
}

template <typename T>
Array<T>::Array(const Array& other):m_size(other.m_size) {
	m_data = new T[m_size];
	for (int i = 0; i < m_size; i++)
		m_data[i] = other.m_data[i];
}

template <typename T>
Array<T>::~Array() {
	delete[] m_data;
}

template <typename T>
int Array<T>::GetSize() const {
	return m_size;
}

template <typename T>
void Array<T>::SwapArrays(Array& other) {
	using std::swap;
	swap(m_size, other.m_size);
	swap(m_data, other.m_data);
}


template <typename T>
int Array<T>::FindElement(const T& element) {
	for (int i = 0; i < m_size; i++)
		if (m_data[i] == elemnt)
			return i;
	return -1;
}

template <typename T>
void Array<T>::Print() const {
	using std::cout;
	cout << "[ ";
	for (int i = 0; i < m_size; i++)
		cout << m_data[i] << " ";
	cout << "]";
}

template <typename T>
void Array<T>::Scan() {
	for (int i = 0; i < m_size; i++)
		std::cin >> m_data[i];
}

template <typename T>
void Array<T>::Sorting() {
	for (int i = 0; i < m_size - 1; i++) {
		bool check = 0;
		for (int j = 0; j < m_size - i - 1; j++)
			if (m_data[j] > m_data[j + 1]) {
				check = 1; 
				std::swap(m_data[j], m_data[j + 1]);
			}
		if (!(check)) break;
	}
}

template <typename T>
void Array<T>::PasteElementByIndex(const int index, const T element) {
	if (index > m_size || index < 0) return;
	m_data[index] = element;
}

template <typename T>
void Array<T>::DelElementByIndex(const int index) {
	if (index > m_size || index < 0) return;
	T* back = new T[m_size - 1];
	int i = 0, j = 0;
	while (i < m_size) {
		if (i != index) {
			back[j] = m_data[i];
			i++;
			j++;
		}
		else
			i++;
	}
	m_data = back;
	m_size--;
}

template <typename T>
void Array<T>::DelElement(const T& element) {
	T* back = new T[m_size - 1];
	bool in_array = false;
	for (int i = 0, j = 0; i < m_size; i++, j++) {
		if (m_data[i] == element) {
			i++;
			in_array = true;
			break;
		}
		else 
			back[j] = m_data[i];
		
	}
	(in array) ? m_data = back : return;
}

template <typename T>
void Array<T>::DelAllElements(const T& element) {
	bool in_array = false;
	for (int i = 0; i < m_size; i++) {
		if (m_data[i] == element) {
			DelElmentByIndex(i);
			i--;
		}
	}
}

template <typename T>
T Array<T>::FindMin() {
	T element = m_data[0];
	for (int i = 1; i < m_size; i++)
		if (m_data[i] > element)
			element = m_data[i];
	return element;
}

template <typename T>
T Array<T>::FindMax() {
	T element = m_data[0];
	for (int i = 1; i < m_size; i++)
		if (m_data[i] < element)
			element = m_data[i];
	return element;
}

//итераторская тема
template <typename T>
Iterator<T> Array<T>::begin() {
	return Iterator<T>(m_data);
}

template <typename T>
Iterator<T> Array<T>::end() {
	return Iterator<T>(m_data + m_size);
}

template <typename T> typename
Array<T>::Iterator Array<T>::GetElement(Iterator<T> pos, const T& element) {
	insert(iterator.m_pos, value);
	iterator.m_pos++;
	return iterator;
}

template <typename T>
Iterator Array<T>::GetElementInRange(Iterator<T> from, Iterator<T> to) {

}

//перегрузки
template <typename T>
T& Array<T>::operator[](const int index) {
	assert(index >= 0 || index < m_size);
	return m_data[index];
}

template <typename T>
const T& Array<T>::operator[](const int index) const {

}

template <typename T> typename
Array<T>::Array& Array<T>::operator = (const Array& other) {
	if (this == other) return *this;

	if (m_size != other.m_size) {
		m_size = other.m_size;
		delete[] m_data;
		m_data = new T[m_size];
	}

	for (int i = 0; i < m_size; i++)
		m_data[i] = other.m_data[i];

	return *this;
}

template <typename T> typename
Array<T>::Array Array<T>::operator + (const T& element) const {
	Array back;
	back.m_size = m_size + 1;
	back.m_data = new T[back.m_size];

	for (int i = 0; i < m_size; i++)
		back.m_data[i] = m_data[i];

	back.m_data[m_size] = element;

	return back;
}

template <typename T>typename
Array<T>::Array& Array<T>::operator += (const T& element) {
	*this = *this + element;
	return *this;
}

template <typename T>typename
Array<T>::Array Array<T>::operator + (Array& other) const {
	Array back;
	back.m_size = m_size + other.m_size;
	back.m_data = new T[back.m_size];

	for (int i = 0; i < back.m_size; i++) {
		if (i < m_size)
			back.m_data[i] = m_data[i];
		back.m_data[i] = m_data[i];
	}
	return back;
}

template <typename T>typename
Array<T>::Array& Array<T>::operator += (Array& other) {
	*this = *this + other;
	return *this;
}

template <typename T>typename
bool Array<T>::operator == (const Array& other) const {
	if (m_size != other.m_size) return false;

	for (int i = 0; i < m_size; i++)
		if (m_data[i] != other.m_data[i])
			return false;

	return true;
}

template <typename T>
bool Array<T>::operator != (const Array& other) const {
	return (!(*this == other));
}

//Iterator

