#ifndef ARRAY_H
#define ARRAY_H

template<typename T>
class Array {
public: 
	Array();
	Array(const T* array, const int size);
	Array(const Array& other);
	~Array();

	int GetSize() const;

	void SwapArrays(Array& other);

	int FindElement(const T& element);
	//возвращает индекс первого совпавшего элемента, либо -1, если совпадений нет

	void Print() const;
	void Scan();

	void Sorting();

	void PasteElementByIndex(const int index, const T element);
	//Если индекс некорректный, вернуть false;

	void DelElementByIndex(const int index);
	//Если индекс некорректный, вернуть false;

	void DelElement(const T& element);
	//первое вхождение

	void DelAllElements(const T& element);
	//delete everyone element in array

	T FindMin();
	T FindMax();

	Iterator<T> begin();
	Iterator<T> end();
	//Метод end должен возвращать итератор не на последний элемент, а за позицию после него

	Iterator GetElement(Iterator<T> pos, const T& element);

	Iterator GetElementInRange(Iterator<T> from, Iterator<T> to);

	T& operator[](const int index);
	const T& operator[](const int index) const;
	Array& operator = (const Array& other);
	Array operator + (const T& element) const;
	Array& operator += (const T& element);
	Array operator + (Array& other) const;
	Array& operator += (Array& other);
	bool operator == (const Array& other) const;
	bool operator != (const Array& other) const;

private:
	int m_size = 0;
	T* m_data;
};

template <typename T>
class Iterator: 
public:
	Iterator<T>(T* m_data = nullptr);

	T& operator* ();
	
	Iterator<T>& operator ++();
	Iterator<T> operator ++(const int);
	Iterator<T>& operator --();
	Iterator<T> operator --(const int);
	Iterator<T> operator = (const int& value);
	Iterator<T> operator += (const int& value);
	Iterator<T> operator -= (const int& value);

	bool operator == (const Iterator& other);
	bool operator != (const Iterator& other);
private:
	T* m_data;
};
#endif // ARRAY_H 