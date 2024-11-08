#pragma once

class BoolVector {

	typedef unsigned char UC;
	static const int cell_size = 8; // sizeof(UC) * 8

public:

	BoolVector();
	BoolVector(const int length, const bool value);
	BoolVector(const UC* array);
	BoolVector(const BoolVector& other);

	~BoolVector();

    int CountOfBit();

    void SwapVectors(BoolVector& other);

    void Scan();
    void Print();

    void Inversion();
    void Inversion(int index);

    void Set0(int index);
    void Set0(int index, int component_count);
    void Set0();
    void Set1(int index);
    void Set1(int index, int component_count);
    void Set1();

    int WeightVector();


    BoolVector& operator & (BoolVector& other);
    BoolVector& operator &= (BoolVector& other);
    BoolVector& operator | (BoolVector& other);
    BoolVector& operator |= (BoolVector& other);
    BoolVector& operator ^ (BoolVector& other);
    BoolVector& operator ^= (BoolVector& other);
    BoolVector& operator << (int value);
    BoolVector& operator >> (int value);
    BoolVector& operator <<= (int value);
    BoolVector& operator >>= (int value);
    BoolVector& operator ~ ();
    BoolVector& operator = (BoolVector& other);

    bool operator == (BoolVector& other);
    bool operator != (BoolVector& other);
    

private:
	UC *m_cells = nullptr;//ячейки
	int m_cell_count = 0;//кол-во ячеек
	int m_length = 0;//длина

    class BoolRank;
};

/*
Необходимые методы класса:


Необходимые перегрузки:
- получение компоненты ([ ], см. примечание ниже);
*/