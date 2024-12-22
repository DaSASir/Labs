#pragma once

class BoolVector {
public:
    class BoolRank;
    using Cell = unsigned char;
    static const int CellSize = 8;

public:
	BoolVector();
	BoolVector(const int length, const bool value = 0);
	BoolVector(const char* array, const int size_a);
	BoolVector(const BoolVector& other);
	~BoolVector();

    int CountOfBit() const;
    int CountOfCell() const;
    bool BitValue(int index) const;
    int WeightVector() const;

    void SwapVectors(BoolVector& other);

    void Scan();
    void Print() const;

    void Inversion();
    void Inversion(const int index);

    void Set(const bool value, const int index);
    void Set(const bool value,const int index,const int component_count);
    void Set(const bool value);

    BoolRank operator [] (const int index);
    BoolVector operator & (const BoolVector& other);
    BoolVector& operator &= (const BoolVector& other);
    BoolVector operator | (const BoolVector& other);
    BoolVector& operator |= (const BoolVector& other);
    BoolVector operator ^ (const BoolVector& other);
    BoolVector& operator ^= (const BoolVector& other);
    BoolVector operator << (const int value);
    BoolVector operator >> (const int value);
    BoolVector& operator <<= (const int value);
    BoolVector& operator >>= (const int value);
    BoolVector operator ~ () const;
    BoolVector& operator = (const BoolVector& other);

    bool operator == (const BoolVector& other) const;  

private:
    static Cell _mask(int index);

private:
	Cell* m_cells = nullptr;//ячейки
	int m_cell_count = 0;//кол-во ячеек
	int m_length = 0;//длина
};

class BoolVector::BoolRank {
public:
    BoolRank() = default;
    BoolRank(Cell* cell, Cell mask);
    BoolRank& operator=(const BoolRank& other);
    BoolRank& operator=(bool value);
    operator bool() const;

private:
    Cell* m_cell = nullptr;
    Cell m_mask = 0;
};

std::ostream& operator<<(std::ostream& stream, const BoolVector& bv);
std::istream& operator>>(std::istream& stream, BoolVector& bv);