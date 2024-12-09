#include "List.h"

//yellow
template <typename T>
List<T>::List() 
    : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
List<T>::List(const T* array, int size_a) : List() {
    for (int i = 0; i < size_a; i++) 
        AddTail(array[i]);
}

template <typename T>
List<T>::List(const List<T>& other) : List() {
    for (Iterator i = other.begin(); i != other.end(); i++)
        AddTail(*i);
}

template <typename T>
List<T>::~List() {
    Clear();
}

template <typename T>
int List<T>::GetSize() const {
    return size;
}

template <typename T>
void List<T>::Swap(List<T>& other) {
    using std::swap;
    swap(head, other.head);
    swap(tail, other.tail);
    swap(size, other.size);
}

template <typename T>
void List<T>::Print() const {
    using std::cout;
    using std::endl;
    cout << "[ ";
    Node<T> adapter = head;
    while (adapter) {
        cout << adapter->data << " ";
        adapter = adapter->next;
    }
    cout << "]" << endl;
}

template <typename T>
void List<T>::Scan() {
    using std::cin;
    using std::cout;

    cout << "Введите кол-во элементов: ";
    cin >> size;

    cout << "Введите элементы: " << std::endl;
    for (int i = 0; i < size; i++) {
        T x;
        cin >> x;
        AddTail(x);
    }
}

template <typename T>
Node<T>* List<T>::FindByKey(const T& key) const {
    Node<T>* back = head;
    while (back) {
        if (back->data == key)
            return back;
        
        back = back->next;
    }
    return nullptr;
}

template <typename T>
void List<T>::AddTail(const T& value) {
    Node<T>* new_cell = new Node<T>(value, tail, nullptr);
    if (tail) 
        tail->next = new_cell;
    else 
        head = new_cell;
    
    tail = new_cell;
    size++;
}

template <typename T>
void List<T>::AddHead(const T& value) {
    Node<T>* new_cell = new Node<T>(value, nullptr, head);
    if (head) 
        head->prev = new_cell;
    else 
        tail = new_cell;
    
    head = new_cell;
    size++;
}

template <typename T>
void List<T>::DelTail() {
    if (IsEmpty()) return;

    Node<T>* temp = tail;
    tail = tail->prev;
    if (tail)
        tail->next = nullptr;
    else 
        head = nullptr;
    delete temp;
    size--;
}

template <typename T>
void List<T>::DelHead() {
    if (IsEmpty()) return;

    Node<T>* temp = head;
    head = head->next;
    if (head) 
        head->prev = nullptr;
    else 
        tail = nullptr;
    
    delete temp;
    size--;
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& other) {
    List back(other);
    return back;
}

template <typename T>
T& List<T>::operator[](int index) {
    if (index < 0 || index >= size) return;

    Node<T>* adapter = head->next;
    if (int i = 0; i < index; i++)
        adapter = adapter->next;

    return adapter->data;
}

template <typename T>
const T& List<T>::operator[](int index) const {
    if (index < 0 || index >= size) return;

    Node<T>* adapter = head->next;
    if (int i = 0; i < index; i++)
        adapter = adapter->next;

    return adapter->data;
}

template <typename T>
bool List<T>::operator==(const List<T>& other) const {
    if (size != other.size) return false;

    Node<T>* a1 = head;
    Node<T>* a2 = other.head;
    
    while (a1 && a2) {
        if (a1->data != a1->data)
            return false;
        a1 = a1->next;
        a2 = a2->next;
    }

    return true;
}

template <typename T>
bool List<T>::operator!=(const List<T>& other) const {
    return !(this == other);
}

//green
template <typename T>
void List<T>::AddByPosition(int pos, const T& value) {
    if (pos == 0) {
        AddHead(value);
        return;
    }
    if (pos >= size) {
        AddTail(value);
        return;
    }

    Node<T>* adapter = head;
    for (int i = 0; i < pos - 1; ++i) 
        adapter = adapter->next;
    

    Node<T>* new_cell = new Node<T>(value, adapter, adapter->next);
    adapter->next->prev = new_cell;
    adapter->next = new_cell;

    size++;
}

template <typename T>
void List<T>::AddAfterKey(const T& key, const T& value) {
    Node<T>* adapter = FindByKey(key);
    if (adapter) {
        Node<T>* new_cell = new Node<T>(value, adapter, adapter->next);
        if (adapter->next) 
            adapter->next->prev = new_cell;
        else 
            tail = new_cell;

        adapter->next = new_cell;
        size++;
    }
}

template <typename T>
void List<T>::DelByPosition(int pos) {
    if (pos >= size) return;

    if (pos == 0) {
        AddHead();
        return;
    }
    if (pos == listSize - 1) {
        AddTail();
        return;
    }

    Node<T>* adapter = head;
    for (int i = 0; i < pos; ++i) 
        adapter = adapter->next;

    adapter->prev->next = adapter->next;
    adapter->next->prev = adapter->prev;
    delete adapter;
    size--;
}

template <typename T>
void List<T>::DelAfterKey(const T& key) {
    Node<T>* adapter = FindByKey(key);
    if (adapter) {
        if (adapter == head) 
            DelHead();
        else if (adapter == tail) 
            DelTail();
        else {
            adapter->prev->next = adapter->next;
            adapter->next->prev = adapter->prev;
            delete adapter;
            size--;
        }
    }
}

template <typename T>
T List<T>::FindMax() const {
    T max_el = head->data;
    Node<T>* adapter = head->next;
    while (adapter) {
        if (adapter->data > max_el)
            max_el = adapter->data;
        
        adapter = adapter->next;
    }
    return max_el;
}

template <typename T>
T List<T>::FindMin() const {
    T min_el = head->data;
    Node<T>* adapter = head->next;
    while (adapter) {
        if (adapter->data < min_el)
            min_el = adapter->data;
        
        adapter = adapter->next;
    }
    return min_el;
}

template <typename T>
bool List<T>::IsEmpty() const {
    return (size == 0);
}

template <typename T>
void List<T>::Clear() {
    while (!IsEmpty())
        DelHead();
}

template <typename T>
List<T> List<T>::operator+(const List<T>& other) const {
    List<T> sum(*this);
    sum += other;
    return sum;
}

template <typename T>
List<T>& List<T>::operator+=(const List<T>& other) {
    for (Iterator it = other.begin(); it != other.end(); it++)
        this->AddTail(*it);
    
    return *this;
}

//no color
template <typename T>
std::ostream& operator<<(std::ostream& os, const List<T>& list) {
    os << "[ ";
    for (Iterator i = list.begin(); i != list.end(); i++)
        os << *i << " ";
    os << "]";

    return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, List<T>& list) {
    for (Iterator i = list.begin(); i != list.end(); i++) 
        is >> *i;

    return is;
}

template <typename T>
typename List<T>::Iterator List<T>::begin() {
    return Iterator(head);
}

template <typename T>
typename List<T>::Iterator List<T>::end() {
    return Iterator(nullptr);
}

template <typename T>
typename List<T>::ConstIterator List<T>::begin() const {
    return ConstIterator(head);
}

template <typename T>
typename List<T>::ConstIterator List<T>::end() const {
    return ConstIterator(nullptr);
}

template <typename T>
void List<T>::FindByIterator(const T& value) {
    for (Iterator it = begin(); it != end(); it++)
        if (*it == value)
            return it;

    return end();
}

template <typename T>
void List<T>::AddByIterator(const T& value, Iterator pos) {
    if (pos == begin())
        AddHead(value);
    else if (pos == end())
        AddTail(value);
    else {
        int index = 0;
        for (Iterator i = begin(); i != pos; i++)
            index++;
        AddByPosition(index, value);
    }
}

template <typename T>
void List<T>::DelByIterator(Iterator pos) {
    if (pos == end()) return;

    if (pos == head)
        DelHead();
    else if (pos == tail)
        DelTail();
    else{
        int index = 0;
        for (Iterator i = begin(); i != pos; i++)
            index++;
        DelByPosition(index, value);
    }
}

template <typename T>
void List<T>::DelRange(Iterator from, Iterator to) {
    while (from != to) {
        DelByIterator(from);
        from++;
    }
}

template <typename T>
void List<T>::Sorting() {
    if (size < 2) return;

    for (Iterator i = begin(); i != end(); i++)
        for (Iterator j = begin(); j != end(); j++)
            if (*i < *j)
                std::swap(i.cell->data, j.cell->data);
}


//iteartor
template <typename T>
T& List<T>::Iterator::operator*() {
    return cell->data;
}
template <typename T>
List<T>::Iterator& List<T>::Iterator::operator++() {
    cell = cell->next;
    return *this;
}

template <typename T>
List<T>::Iterator List<T>::Iterator::operator++(int) {
    Iterator old = *this;
    (*this)++;
    return old;
}

template <typename T>
List<T>::Iterator& List<T>::Iterator::operator--() {
    cell = cell->prev;
    return *this;
}

template <typename T>
List<T>::Iterator List<T>::Iterator::operator--(int) {
    Iterator old = *this;
    (*this)--;
    return old;
}

template <typename T>
bool List<T>::Iterator::operator==(const Iterator& other) const {
    return cell == other.cell;
}

template <typename T>
bool List<T>::Iterator::operator!=(const Iterator& other) const {
    return cell != other.cell;
}
