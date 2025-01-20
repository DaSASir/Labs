#pragma once
#include "..\..\laba-Boolean_vector-Tychinsky\laba-Boolean_vector-Tychinsky\Vector.h"

struct Plenty : protected  BoolVector {
	static const int start_table = 32;
	static const int end_table = 127;
	static const int size_table = end_table - start_table;

	Plenty();
	Plenty(const char* array);
	Plenty(const Plenty& other);
	~Plenty();

	void Print() const;
	void Scan();

	bool InPlenty(const char element) const;
	int Capacity() const;

	char MaxElement() const;
	char MinElement() const;

	Plenty operator ~ () const;
	Plenty& operator = (const Plenty& other);
	Plenty operator | (const Plenty& other) const;
	Plenty& operator |= (const Plenty& other);
	Plenty operator & (const Plenty& other) const;
	Plenty& operator &= (const Plenty& other);
	Plenty operator / (const Plenty& other) const;
	Plenty& operator /= (const Plenty& other);
	Plenty operator + (const char value) const;
	Plenty& operator += (const char value);
	Plenty operator - (const char value) const;
	Plenty& operator -= (const char value);
	bool operator == (const Plenty& other) const;
	bool operator != (const Plenty& other) const;

	bool GetBitBV(const int index) const;
	void SetBit(const bool bit, const int index);
};

std::ostream& operator << (std::ostream& stream, const Plenty& set);
std::istream& operator >> (std::istream& stream, Plenty& set);
