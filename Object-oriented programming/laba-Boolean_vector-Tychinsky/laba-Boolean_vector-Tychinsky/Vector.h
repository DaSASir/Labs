#pragma once

class BoolVector {
	static const int cell_size = 8; // sizeof(UC) * 8

public:

	BoolVector();
	BoolVector(const int length, const bool value);
	BoolVector(const char* array);
	BoolVector(const BoolVector& other);

	~BoolVector();

    int CountOfBit() const;

    void SwapVectors(BoolVector& other);

    void Scan();
    void Print() const;

    void Inversion();
    void Inversion(const int index);

    void Set(const bool value, const int index);
    void Set(const bool value,const int index,const int component_count);
    void Set(const bool value);

    int WeightVector() const;

    class BoolRank;
    BoolRank operator [] (const int index);
    BoolVector operator & (const BoolVector& other);
    BoolVector& operator &= (const BoolVector& other);
    BoolVector operator | (const BoolVector& other);
    BoolVector& operator |= (const BoolVector& other);
    BoolVector operator ^ (const BoolVector& other);
    BoolVector& operator ^= (const BoolVector& other);
    BoolVector& operator << (const int value);
    BoolVector& operator >> (const int value);
    BoolVector& operator <<= (const int value);
    BoolVector& operator >>= (const int value);
    BoolVector& operator ~ ();
    BoolVector& operator = (const BoolVector& other);

    bool operator == (const BoolVector& other) const;  

private:
	bool* m_cells = nullptr;//ячейки
	int m_cell_count = 0;//кол-во ячеек
	int m_length = 0;//длина
};

class BoolVector::BoolRank {
public:
    BoolRank(bool& cell, const int index);

    BoolRank& operator = (const bool value);
    BoolRank& operator = (const BoolRank& other);
    BoolRank& operator |= (const bool value);
    BoolRank& operator &= (const bool value);
    BoolRank& operator ^= (const bool value);
    BoolRank& operator ~ ();

    bool operator == (const bool value) const;
    bool operator != (const bool value) const;

private:
    bool& m_cell;
    int m_index;
};

std::ostream& operator << (std::ostream& stream, const BoolVector& object);
std::istream& operator >> (std::istream& stream, BoolVector& object);