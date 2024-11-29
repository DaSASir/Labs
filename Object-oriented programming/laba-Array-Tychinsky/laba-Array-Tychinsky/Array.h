#pragma once

class Array {
public: 
	Array();
	Array(const char* array);
	Array(const Array& other);
	~Array();

	int GetSize();

	void Swap(Array& other);

	int FindElement(const int value);

	void Print() const;
	void Scan();

	void Sorting();

	void InsertingByIndex(const int index);

	void DeleteByIndex(const int index);
	void DeleteByValue(const int value);
	void DeleteAllByValue(const int value);

	int Min() const;
	int Max() const;

	Iterator begin();
	Iterator end();

	void InsertingByIterator();

	void DeleteByIterator();



	Array operator[] (const int index);
	Array operator = (const Array& other);
	Array operator + (const int value);
	Array operator += (const int value);
	Array operator + (const Array& otrher);
	Array operator += (const Array& otrher);
	bool operator == (const Array& other);
	bool operator != (const Array& other);


private:
	int* m_array;
	int m_size = 0;
};

class Iterator {
public:
	Iterator(int* object);

	int& operator*();
	const int& operator*() const;

	int operator++();
	int operator--();

	int operator++(int);
	int operator--(int);

	bool operator==(const int& other) const;
	bool operator!=(const int& other) const;
private:
	int* m_cell = nullptr;
};