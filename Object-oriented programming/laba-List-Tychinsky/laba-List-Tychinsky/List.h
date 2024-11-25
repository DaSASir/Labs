#pragma once
#include "C:\GitHub_Repositories\Labs\Object-oriented programming\laba-Array-Tychinsky\laba-Array-Tychinsky\Array.h"

class List {

public:
	//- конструкторы (по умолчанию, конструктор из класса-массива, конструктор копирования);
	List();
	List(const Array& array);
	List(const List& other);
	//- деструктор;
	~List();

	//- получение размера списка;
	int Size();

	//- обмен содержимого с другим списком (swap);
	void Swap(List& other);

	//- ввод/вывод в консоль (потоковый);
	void Print();
	void Scan();

	//- получение итераторов на начало/конец списка (методы должны называться begin и end. Метод end должен возвращать итератор не на последний элемент, а за позицию после него);

	//- поиск элемента по ключу (возвращает указатель/итератор на элемент или nullptr, если элемента нет в списке);
	Node* FindKey(const char key);

	//- добавление элемента (в голову, хвост, на позицию, после ключа (после первого вхождения), по итератору);
	void AddToTail(const char data);
	void AddToHead(const char data);
	void AddAfterKey(const char data, Node* key);
	void AddToIterator(const char data, Node* key);

	//- удаление элемента (из головы, хвоста, позиции, по ключу (первое вхождение), по итератору);
	void DelHead();
	void DelTail();
	void DelKey(Node* p);
	void DelIterator(Node* p);

	//- удаление диапазона элементов с помощью итераторов;

	//- поиск максимального/минимального элемента;
	char MaxElement();
	char MinElement();
	//- isEmpty() - возвращает true, если список пуст;
	bool IsEmpty();

	//- очистка списка;
	void Clear();

	//- сортировка списка;
	void Sorting();

	//- присваивание (=);
	List operator = (const List& other);
	//- получение ссылки на ключ элемента ([ ]);
	Node* operator [] (const int index);
	//- сравнение (==, !=);
	bool operator == ( List& other);
	bool operator != ( List& other);
	//- сложение (конкатенация) списков (+, +=).
	List operator + (const List& other);
	List operator += (const List& other);

private:
	Node* head;
	Node* tail;
};

class Node {
	char m_data;
	Node* last, * next;

public:
	Node(char k = 0, Node* lst = nullptr, Node* nxt = nullptr);
	char Data();

	friend class List;
};

class Iterator {
	//не знаю что это и зачем)
};