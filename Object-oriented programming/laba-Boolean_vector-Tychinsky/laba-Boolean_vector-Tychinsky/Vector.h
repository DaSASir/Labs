#pragma once

class BoolVector {

	typedef unsigned char UC;
	typedef unsigned int UI;
	static const int cell_size = 8; // sizeof(UC) * 8

public:

	BoolVector();
	BoolVector(const int length, const bool value);
	BoolVector(const char* array);
	BoolVector(const BoolVector& other);

	~BoolVector();

    int CountOfBit();

    void SwapVectors(BoolVector& other);

    void Scan();
    void Print() const;

    void Inversion();
    void Inversion(int index);

    void Set(const bool value, const int index);
    void Set(const bool value,const int index,const int component_count);
    void Set(const bool value);

    int WeightVector() const;

    BoolVector& operator [] (const int index);
    BoolVector& operator & (const BoolVector& other);
    BoolVector& operator &= (const BoolVector& other);
    BoolVector& operator | (const BoolVector& other);
    BoolVector& operator |= (const BoolVector& other);
    BoolVector& operator ^ (const BoolVector& other);
    BoolVector& operator ^= (const BoolVector& other);
    BoolVector& operator << (const int value);
    BoolVector& operator >> (const int value);
    BoolVector& operator <<= (const int value);
    BoolVector& operator >>= (const int value);
    BoolVector& operator ~ ();
    BoolVector& operator = (const BoolVector& other);

    bool operator == (const BoolVector& other);  

private:
	UC *m_cells;//ячейки
	int m_cell_count;//кол-во ячеек
	int m_length;//длина

    class BoolRank;
};

class BoolVector::BoolRank {
public:
    BoolRank(UC* m_cells, const int& index);
    ~BoolRank();

    BoolRank& operator = (const BoolRank& other);
    BoolRank& operator = (const bool value);
    bool operator | (const bool value) const;
    bool operator & (const bool value) const;
    bool operator ~ () const;
    bool operator ^ (const bool value) const;
    bool operator == (const BoolRank& other) const;
    bool operator == (const bool value) const;

    operator bool() const;

private:
    UC* m_cell = nullptr;
    UI m_mask = 1 << 7;
};

/*
Необходимые методы класса:


Необходимые перегрузки:
- получение компоненты ([ ], см. примечание ниже);

1. Имеет доступ к ячейке, содержащей i-ую компоненту;
2. Содержит информацию о позиции компоненты в ячейке.
Т.о., используя битовую маску, объект класса BoolRank может изменять
значения нужного бита.

Всё, что после этого будет нужно реализовать - перегрузки стандартных операций 
(присваивание,
битовое сложение,
умножение,
инверсия,
исключающее ИЛИ.
Рекомендуется также определить операции сравнения и присваивание, 
как между объектами класса BoolRank, так и с одним из базовых типов 
(int/bool/char),
а также конвертацию типа Rank в один из базовых типов.
*/