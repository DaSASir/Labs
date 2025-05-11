#pragma once

class BoolVector {
public:
    class BoolRank;
    using Cell = unsigned char;
    static const int CellSize = 8;

public:
	BoolVector();
	BoolVector(const int size);
	BoolVector(const int length, const bool value);
	BoolVector(const char* array, const int size);
	BoolVector(const BoolVector& other);
	~BoolVector();

    void Print() const;
    void Scan();

    int CountOfBit() const;
    int CountOfCell() const;
    bool BitValue(const int index) const;
    int WeightVector() const;

    void SwapVectors(BoolVector& other);

    void Inversion();
    void Inversion(const int index);

    void Set(const bool value);
    void Set(const bool value, const int index);
    void Set(const bool value, const int index, const int component_count);

    BoolRank operator [] (const int index);
    BoolVector operator & (const BoolVector& other) const;
    BoolVector& operator &= (const BoolVector& other);
    BoolVector operator | (const BoolVector& other) const;
    BoolVector& operator |= (const BoolVector& other);
    BoolVector operator ^ (const BoolVector& other) const;
    BoolVector& operator ^= (const BoolVector& other);
    BoolVector operator << (const int value) const;
    BoolVector operator >> (const int value) const;
    BoolVector& operator <<= (const int value);
    BoolVector& operator >>= (const int value);
    BoolVector operator ~ () const;
    BoolVector& operator = (const BoolVector& other);

    bool operator == (const BoolVector& other) const;  
    bool operator != (const BoolVector& other) const;  

private:
    static Cell _mask(const int index);

protected:
	Cell* m_cells = nullptr;
	int m_cell_count = 0;
	int m_length = 0;
};

class BoolVector::BoolRank {
public:
    BoolRank() = default;
    BoolRank(Cell* cell, Cell mask);
    BoolRank& operator=(const BoolRank& other);
    BoolRank& operator=(const bool value);
    operator bool() const;

private:
    Cell* m_cell = nullptr;
    Cell m_mask = 0;
};

std::ostream& operator<<(std::ostream& stream, const BoolVector& bv);
std::istream& operator>>(std::istream& stream, BoolVector& bv);