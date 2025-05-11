#pragma once
#include <iostream>
#include "assert.h"

template <typename T>
class List {
    struct Node;
public:
    template <typename ItemType>
    class TemplateIterator;
    using Iterator = TemplateIterator<T>;
    using ConstIterator = TemplateIterator<const T>;

public:
    List();
    List(const T* array, const int size);
    List(const List<T>& other);
    ~List();

    int GetSize() const;
    void Swap(List<T>& other);

    void Print() const;
    void Scan();

    Iterator begin();
    Iterator end();
    ConstIterator begin() const;
    ConstIterator end() const;

    bool IsEmpty() const;
    void Clear();
    void Sorting();

    void AddHead(const T& value);
    void AddTail(const T& value);
    void AddToPosition(const int pos, const T& value);
    void AddAfterKey(const T& key, const T& value);
    void AddByIterator(const T& value, Iterator pos);

    void DelHead();
    void DelTail();
    void DelFromPosition(const int pos);
    void DelFromKey(const T& key);
    void DelByIterator(Iterator pos);
    void DelRange(Iterator from, Iterator to);

    T FindMax() const;
    T FindMin() const;

    ConstIterator FindMaxIt() const;
    ConstIterator FindMinIt() const;

    Node* FindByKey(const T& key) const;
    Iterator FindByIterator(const T& key) const;

    List<T>& operator=(const List<T>& other);
    T& operator[](const int index);
    const T& operator[](const int index) const;
    bool operator==(const List<T>& other) const;
    bool operator!=(const List<T>& other) const;
    List<T> operator+(const List<T>& other) const;
    List<T>& operator+=(const List<T>& other);

private:
    Node* m_head = nullptr;
    Node* m_tail = nullptr;
    int m_size = 0;
};

template <typename T>
struct List<T>::Node {
    Node(Node* next = nullptr, Node* prev = nullptr)
        : m_next(next), m_prev(prev) {};

    Node(const T& value, Node* next = nullptr, Node* prev = nullptr)
        : m_data(value), m_next(next), m_prev(prev) {};

    T m_data;
    Node* m_next = nullptr;
    Node* m_prev = nullptr;
};

template <typename T>
template <typename ItemType>
class List<T>::TemplateIterator {
public:
    TemplateIterator(Node* cell) : m_cell(cell) {}

    ItemType& operator*();
    const ItemType& operator*() const;
    TemplateIterator operator++();
    TemplateIterator operator--();
    TemplateIterator operator++(int);
    TemplateIterator operator--(int);
    bool operator==(const TemplateIterator& other) const;
    bool operator!=(const TemplateIterator& other) const;

    TemplateIterator operator += (const int amount);
    TemplateIterator operator -= (const int amount);

    Node* GetNode() { return m_cell; };

protected:
    Node* m_cell = nullptr;
};

//конструкторы и деструктор
template <typename T>
List<T>::List(): m_head(new Node()), m_tail(new Node()) {
    m_head->m_next = m_tail;
    m_tail->m_prev = m_head;
}

template <typename T>
List<T>::List(const T* array, const int size) : List() {
    for (int i = 0; i < size; i++)
        AddTail(array[i]);
}

template <typename T>
List<T>::List(const List<T>& other) : List() {
    for (ConstIterator i = other.begin(); i != other.end(); i++)
        AddTail(*i);
}

template <typename T>
List<T>::~List() {
    Clear();
    delete m_head;
    delete m_tail;
}

//вывод размера и обмен списков
template <typename T>
int List<T>::GetSize() const {
    return m_size;
}

template <typename T>
void List<T>::Swap(List<T>& other) {
    using std::swap;
    swap(m_head, other.m_head);
    swap(m_tail, other.m_tail);
    swap(m_size, other.m_size);
}

//ввод и вывод
template <typename T>
void List<T>::Print() const {
    std::cout << "{ ";
    for (ConstIterator it = begin(); it != end(); it++)
        std::cout << *it << ' ';
    std::cout << "}\n";
}

template <typename T>
void List<T>::Scan() {
    Clear();

    int cell_count;
    std::cout << "Введиет кол-во элементов: ";
    std::cin >> cell_count;

    std::cout << "Введите элементы:\n";
    for (int i = 0; i < cell_count; i++) {
        T element;
        std::cin >> element;
        AddTail(element);
    }
}

//итераторы начала и конца списка
template <typename T> typename
List<T>::Iterator List<T>::begin() {
    return Iterator(m_head->m_next);
}

template <typename T> typename
List<T>::Iterator List<T>::end() {
    return Iterator(m_tail);
}

template <typename T> typename
List<T>::ConstIterator List<T>::begin() const {
    return ConstIterator(m_head->m_next);
}

template <typename T> typename
List<T>::ConstIterator List<T>::end() const {
    return ConstIterator(m_tail);
}

//проверка на пустоту, очистка и сортировка
template <typename T>
bool List<T>::IsEmpty() const {
    return (m_head->m_next == m_tail);
}

template <typename T>
void List<T>::Clear() {
    while (!IsEmpty())
        DelTail();
    m_size = 0;
}

template <typename T>
void List<T>::Sorting() {
    for (Iterator it = begin(); it != end(); it++) {
        bool check = 0;
        for (Iterator jt = begin(); jt != end(); jt++)
            if (*it < *jt) {
                std::swap(it.GetNode()->m_data, jt.GetNode()->m_data);
                check = 1;
            }
        if (!check) break;
    }
}

//добавление элемента в голову, в хвост, на позицию, после ключа, по итератору
template <typename T>
void List<T>::AddHead(const T& value) {
    AddByIterator(value, begin());
}

template <typename T>
void List<T>::AddTail(const T& value) {
    AddByIterator(value, end());
}

template <typename T>
void List<T>::AddToPosition(const int pos, const T& value) {
    assert(pos >= 0 && pos < m_size);
    AddByIterator(value, (begin() += pos));
}

template <typename T>
void List<T>::AddAfterKey(const T& key, const T& value) {
    AddByIterator(value, FindByIterator(key));
}

template <typename T>
void List<T>::AddByIterator(const T& value, Iterator pos) {
    Node* cell = pos.GetNode();
    Node* node = new Node(value, cell, cell->m_prev);
    cell->m_prev->m_next = node;
    cell->m_prev = node;
    m_size++;
}   

//удаление элемента из головы, из хвоста, по позиции, после ключа, по итератору
template <typename T>
void List<T>::DelHead() {
    if(!IsEmpty())
        DelByIterator(begin());
}

template <typename T>
void List<T>::DelTail() {
    if (!IsEmpty())
        DelByIterator((--end()));
}

template <typename T>
void List<T>::DelFromPosition(const int pos) {
    assert(pos >= 0 && pos < m_size);
    DelByIterator(begin() += pos);
}

template <typename T>
void List<T>::DelFromKey(const T& key) {
    DelByIterator(FindByIterator(key));
}

template <typename T>
void List<T>::DelByIterator(Iterator pos) {
    if (pos != end()) {
        Node* node = pos.GetNode();
        node->m_prev->m_next = node->m_next;
        node->m_next->m_prev = node->m_prev;
        delete node;
        m_size--;
    }
}

template <typename T>
void List<T>::DelRange(Iterator from, Iterator to) {
    for (Iterator it = from; it != to; it++)
        DelByIterator(it);
}

//вывод максимального и минимального элемента из списка
template <typename T>
T List<T>::FindMax() const {
    if (m_size <= 0) return 0;

    T max = m_head->m_next->m_data;
    for (ConstIterator it = begin(); it != end(); it++)
        if (*it > max)
            max = *it;

    return max;
}

template <typename T>
T List<T>::FindMin() const {
    if (m_size <= 0) return 0;

    T min = m_head->m_next->m_data;
    for (ConstIterator it = begin(); it != end(); it++)
        if (*it < min)
            min = *it;

    return min;
}

template <typename T> typename
List<T>::ConstIterator List<T>::FindMaxIt() const {
    auto i = begin();
    for (auto it = begin(); it != end(); it++) 
        if (*it > *i)
            i = it;

    return i;
}

template <typename T> typename
List<T>::ConstIterator List<T>::FindMinIt() const {
    auto i = begin();
    for (auto it = begin(); it != end(); it++)
        if (*it < *i)
            i = it;

    return i;
}

//нахождение ячейки и итератора по элементу
template <typename T> typename
List<T>::Node* List<T>::FindByKey(const T& key) const {
    Node* node = m_head->m_next;
    while (node != m_tail && node->m_data != key)
        node = node->m_next;

    return node;
}

template <typename T> typename
List<T>::Iterator List<T>::FindByIterator(const T& key) const {
    Node* node = FindByKey(key);
    return Iterator(node);
}

//перегрузки
template <typename T>
List<T>& List<T>::operator=(const List<T>& other) {
    if (*this != other) {
        Clear();
        for (ConstIterator it = other.begin(); it != other.end(); it++)
            AddTail(*it);
    }
    return *this;
}

template <typename T>
T& List<T>::operator[](const int index) {
    assert(index >= 0 && index < m_size);
    Node* back = m_head->m_next;
    for (int i = 0; i < index; i++)
        back = back->m_next;

    return back->m_data;
}

template <typename T>
const T& List<T>::operator[](const int index) const {
    assert(index >= 0 && index < m_size);
    Node* back = m_head->m_next;
    for (int i = 0; i < index; i++)
        back = back->m_next;

    return back->m_data;
}

template <typename T>
bool List<T>::operator==(const List<T>& other) const {
    if (m_size != other.m_size) return false;
    if (m_head == other.m_head) return true;

    for(ConstIterator it = begin(), oit = other.begin(); it != end(); it++, oit++)
        if (*it != *oit) return false;

    return true;
}

template <typename T>
bool List<T>::operator!=(const List<T>& other) const {
    return !(*this == other);
}

template <typename T>
List<T> List<T>::operator+(const List<T>& other) const {
    List<T> back(*this);
    back += other;
    return back;
}

template <typename T>
List<T>& List<T>::operator+=(const List<T>& other) {
    for (ConstIterator it = other.begin(); it != other.end(); it++)
        this->AddTail(*it);

    return *this;
}

//потоковый ввод и вывод
template <typename T>
std::ostream& operator << (std::ostream& stream, const List<T>& list) {
    stream << "{";
    for (auto it = list.begin(); it != list.end(); it++)
        stream << *it << ' ';
    stream << "}\n";

    return stream;
}

template <typename T>
std::istream& operator >> (std::istream& stream, List<T>& list) {
    for (auto it = list.begin(); it != list.end(); it++)
        stream >> *it;

    return stream;
}

//итератор
template <typename T>
template <typename ItemType>
ItemType& List<T>::TemplateIterator<ItemType>::operator*() {
    return m_cell->m_data;

}

template <typename T>
template <typename ItemType>
const ItemType& List<T>::TemplateIterator<ItemType>::operator*() const {
    return m_cell->m_data;
}

template <typename T>
template <typename ItemType>
typename List<T>::template
TemplateIterator<ItemType> List<T>::TemplateIterator<ItemType>::operator++() {
    m_cell = m_cell->m_next;
    return *this;
}

template <typename T>
template <typename ItemType>
typename List<T>::template
TemplateIterator<ItemType> List<T>::TemplateIterator<ItemType>::operator--() {
    m_cell = m_cell->m_prev;
    return *this;
}

template <typename T>
template <typename ItemType>
typename List<T>::template
TemplateIterator<ItemType> List<T>::TemplateIterator<ItemType>::operator++(int) {
    TemplateIterator back = *this;
    m_cell = m_cell->m_next;
    return back;
}

template <typename T>
template <typename ItemType>
typename List<T>::template
TemplateIterator<ItemType> List<T>::TemplateIterator<ItemType>::operator--(int) {
    TemplateIterator bcak = *this;
    m_cell = m_cell->m_prev;
    return bcak;
}

template <typename T>
template <typename ItemType>
bool List<T>::TemplateIterator<ItemType>::operator==(const TemplateIterator& other) const {
    return (m_cell == other.m_cell);
}

template <typename T>
template <typename ItemType>
bool List<T>::TemplateIterator<ItemType>::operator!=(const TemplateIterator& other) const {
    return (m_cell != other.m_cell);
}

template <typename T>
template <typename ItemType>
typename List<T>::template
TemplateIterator<ItemType> List<T>::TemplateIterator<ItemType>::operator += (const int amount) {
    for (int i = 0; i < amount; i++)
        m_cell = m_cell->m_next;
    return *this;
}

template <typename T>
template <typename ItemType>
typename List<T>::template
TemplateIterator<ItemType> List<T>::TemplateIterator<ItemType>::operator -= (const int amount) {
    for (int i = 0; i < amount; i++)
        m_cell = m_cell->m_prev;
    return *this;
}
