#pragma once
#include "C:\GitHub_Repositories\Labs\Object-oriented programming\laba-Boolean_vector-Tychinsky\laba-Boolean_vector-Tychinsky\Vector.h"

struct Plenty :protected BoolVector {
	static const int full_size = 256;

	Plenty();
	Plenty(const char* array);
	Plenty(const Plenty& other);
	~Plenty();

	void Print() const;
	void Scan();

	//проверка наличия элемента в множестве;
	bool InPlenty(const char element);

	int MaxElement() const;
	int MinElement() const;

	//получение мощности множества;
	int Capacity() const;

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
	Plenty operator + (const Plenty& other) const;
	Plenty operator += (const Plenty& other);
	//удаление элемента из множества (-, -=);
	Plenty operator - (const char value) const;
	Plenty operator -= (const Plenty& other);
};

std::ostream& operator << (std::ostream& stream, const Plenty& other);
std::istream& operator >> (std::istream& stream, Plenty& other);
