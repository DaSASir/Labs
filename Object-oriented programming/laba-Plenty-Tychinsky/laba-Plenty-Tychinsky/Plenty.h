#pragma once
#include "..\..\laba-Boolean_vector-Tychinsky\laba-Boolean_vector-Tychinsky\Vector.h"

struct Plenty :protected BoolVector {
	static const int start_table = 32;
	static const int size_table = 127 - start_table;
	char elements[size_table];
	int size;

	Plenty();
	Plenty(const char* array);
	Plenty(const Plenty& other);
	~Plenty();

	void Print() const;
	void Scan();

	//проверка наличия элемента в множестве;
	bool InPlenty(const char element) const;

	char MaxElement() const;
	char MinElement() const;

	//получение мощности множества;
	int Capacity();

	//присваивание (=);
	Plenty operator = (const Plenty& other);
	//сравнение (==, !=);
	bool operator == (const Plenty& other);
	bool operator != (const Plenty& other);
	//объединение множеств (|, |=);
	Plenty operator | (const Plenty& other) const;
	Plenty operator |= (const Plenty& other);
	//пересечение множеств (&, &=);
	Plenty operator & (const Plenty& other) const;
	Plenty operator &= (const Plenty& other);
	//разность множеств (/, /=);
	Plenty operator / (const Plenty& other) const;
	Plenty operator /= (const Plenty& other);
	//получение дополнения (~, множество, состоящее из элементов, которые не входят в исходное множество);
	Plenty operator ~ ();
	//добавление элемента к множеству (+, +=);
	Plenty operator + (const char value) const;
	Plenty operator += (const char value);
	//удаление элемента из множества (-, -=);
	Plenty operator - (const char value) const;
	Plenty operator -= (const char value);
};

std::ostream& operator << (std::ostream& stream, const Plenty& other);
std::istream& operator >> (std::istream& stream, Plenty& other);
