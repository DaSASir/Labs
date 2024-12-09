#ifndef LIST_H
#define LIST_H
#include <iostream>

template <typename T>
class Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(const T& value, Node<T>* prev = nullptr, Node<T>* next = nullptr)
        : data(value), next(next), prev(prev) {}

    friend class List<T>;
};

template <typename T>
class List {
public:
    class Iterator;
    class ConstIterator;
public:
    //----------<YELLOW>----------
    List();
    List(const T* array, int size_a);
    List(const List<T>& other);
    ~List();

    int GetSize() const;

    void Swap(List<T>& other);

    void Print() const;
    void Scan();

    Node<T>* FindByKey(const T& key) const;

    void AddTail(const T& value);
    void AddHead(const T& value);

    void DelTail();
    void DelHead();

    List<T>& operator=(const List<T>& other);
    T& operator[](int index);
    const T& operator[](int index) const;
    bool operator==(const List<T>& other) const;
    bool operator!=(const List<T>& other) const;

    //----------<GREEN>----------
    void AddByPosition(int pos, const T& value);
    void AddAfterKey(const T& key, const T& value);

    void DelByPosition(int pos);
    void DelAfterKey(const T& key);

    T FindMax() const;
    T FindMin() const;

    bool IsEmpty() const;

    void Clear();

    List<T> operator+(const List<T>& other) const;
    List<T>& operator+=(const List<T>& other);

    //----------<NO COLOR>----------
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const List<U>& list);
    template <typename U>
    friend std::istream& operator>>(std::istream& is, List<U>& list);

    Iterator begin();
    Iterator end();

    ConstIterator begin() const;
    ConstIterator end() const;
    
    void FindByIterator(const T& value);

    void AddByIterator(const T& value, Iterator pos);

    void DelByIterator(Iterator pos);
    void DelRange(Iterator from, Iterator to);

    void Sorting();

private:
    Node<T>* head;
    Node<T>* tail;
    int size;
};

template <typename T>
class List<T>::Iterator {
    Node<T>* cell;
public:
    Iterator(Node<T>* c = nullptr) : cell(c) {}

    T& operator*();
    Iterator& operator++();
    Iterator operator++(int);
    Iterator& operator--();
    Iterator operator--(int);
    bool operator==(const Iterator& other) const;
    bool operator!=(const Iterator& other) const;
};

template <typename T>
class List<T>::ConstIterator {
    const Node<T>* cell;
public:
    ConstIterator(const Node<T>* c = nullptr) : cell(c) {}

    const T& operator*() const;
    ConstIterator& operator++();
    ConstIterator operator++(int);
    ConstIterator& operator--();
    ConstIterator operator--(int);
    bool operator==(const ConstIterator& other) const;
    bool operator!=(const ConstIterator& other) const;
};

#include "List.cpp"
#endif 