#include "Array.h"

//yellow
template <typename T>
Array<T>::Array() 
    : data(nullptr), size(0) {}

template <typename T>
Array<T>::Array(const T* array, int size_a) : size(size_a) {
    data = new T[size];
    for (int i = 0; i < size; i++) 
        data[i] = array[i];
    
}

template <typename T>
Array<T>::Array(const Array& other) : size(other.size) {
    data = new T[size];
    for (size_t i = 0; i < size; i++) 
        data[i] = other.data[i];
}

template <typename T>
Array<T>::~Array() {
    delete[] data;
}

template <typename T>
int Array<T>::GetSize() const {
    return size;
}

template <typename T>
void Array<T>::Swap(Array& other) {
    using std::swap;
    swap(size, other.size);
    swap(data, other.data);
}

template <typename T>
int Array<T>::Find(const T& value) const {
    for (int i = 0; i < size; i++) 
        if (data[i] == value) 
            return i;

    return -1;
}

template <typename T>
void Array<T>::Print() const{
    using std::cout;
    cout << "[ ";
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << "]" << std::endl;
}

template <typename T>
void Array<T>::Scan() {
    std::cout << "Введите кол-во элементов: ";
    std::cin >> size;
    T* array = new T[size];
    std::cout << "Введите элементы: " << std::endl;
    for (int i = 0; i < size; i++)
        std::cin >> array[i];
    Array(array, size);
}

template <typename T>
void Array<T>::Sorting() {
    for (int i = 0; i < size - 1; i++) {
        bool check = 0;
        for (int j = 0; j < size - i - 1; j++)
            if (data[j] > data[j + 1]) { 
                check = 1; 
                std::swap(data[j], data[j + 1]); 
            }
        if (!check) break;
    }
}

template <typename T>
bool Array<T>::Insert(int index, const T& value) {
    if (index >= 0 && index < size) {
        size++;
        for (int i = size; i > index; i--)
            data[i] = data[i - 1];
        data[index] = value;
    }
    else if (index == size) {
        size++;
        data[index] = value;
    }
    else return false;

    return true;
}

template <typename T>
bool Array<T>::DelIndex(int index) {
    if (index >= size) return false;
    
    for (int i = index; i < size - 1; i++) 
        data[i] = data[i + 1];
    
    size--;
    return true;
}

template <typename T>
bool Array<T>::DelValue(const T& value) {
    for (int i = 0; i < size; i++) 
        if (data[i] == value) 
            return DelIndex(i);
        
    return false;
}

template <typename T>
T& Array<T>::operator[](int index) {
    assert(index < size && index >= 0);
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const {
    assert(index < size && index >= 0);
    return data[index];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this == other) return *this;

    delete[] data;
    size = other.size;
    data = new T[size];
    for (int i = 0; i < size; i++) 
        data[i] = other.data[i];
    
    return *this;
}


//green
template <typename T>
void Array<T>::DelAll(const T& value) {
    int i = 0;
    while (i < size) {
        if(data[i] == value)
            DelIndex(i);
        else
            i++;
    }
}

template <typename T>
T Array<T>::GetMax() const {
    T max = data[0];
    for (int i = 1; i < size; i++)
        if (max < data[i])
            max = data[i];
    return max;
}

template <typename T>
T Array<T>::GetMin() const {
    T min = data[0];
    for (int i = 1; i < size; i++)
        if (min > data[i])
            min = data[i];
    return min;
}

template <typename T>
Array<T>& Array<T>::operator + (const Array& other) {
    int double_size = m_size + other.m_size;

    Array back(sizeOfTwoObj, 0);

    for (int i = 0, j = 0; i < temp.m_size; i++) {
        if (i < m_size) {
            temp[i] = m_numbers[i];
        }
        else {
            temp[i] = object.m_numbers[j];
            j++;
        }
    }

    return temp;
}

template <typename T>
Array<T>& Array<T>::operator += (const Array& other) {
    *this = *this + other;
    return *this;
}

template <typename T>
bool Array<T>::operator == (const Array& other) {
    if (size != other.size) return false;

    for (int i = 0; i < size; i++)
        if (data[i] != other.data[i])
            return false;

    return true;
}

template <typename T>
bool Array<T>::operator != (const Array& other) {
    return !(*this == other);
}

// no color

template <typename T>
Array<T>::Iterator::Iterator(T* c) 
    : cell(c) {}


template <typename T>
T& Array<T>::Iterator::operator*() {
    return *cell;
}

template <typename T> typename 
Array<T>::Iterator& Array<T>::Iterator::operator++() {
    cell++;
    return *this;
}

template <typename T>
typename Array<T>::Iterator Array<T>::Iterator::operator++(int) {
    Iterator temp = *this;
    cell++;
    return temp;
}

template <typename T>
bool Array<T>::Iterator::operator==(const Iterator& other) const {
    return cell == other.cell;
}

template <typename T>
bool Array<T>::Iterator::operator!=(const Iterator& other) const {
    return cell != other.cell;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& array) {
    os << "[ ";
    for (int i = 0; i < array.GetSize(); i++) 
        os << array[i] << " ";
    
    os << "]" << std::endl;

    return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, const Array<T>& array) {
    for (int i = 0; i < array.GetSize(); i++) {
        std::cout << "Array[" << i << "] = ";
        is >> object[i];
    }

    return is;
}

template <typename T>
typename Array<T>::Iterator Array<T>::begin() {
    return Iterator(data);
}

template <typename T>
typename Array<T>::Iterator Array<T>::end() {
    return Iterator(data + size);
}

template <typename T>
void Array<T>::InsertIt(Iterator it, const T& value) {
    Insert(iterator.m_pos, value);
    it.cell++;
    return it;
}

template <typename T>
void Array<T>::DelIt() {
    DelIndex();
}

template <typename T>
void Array<T>::DelItRange(const Iterator begin, const Iterator end) {
    assert(begin.cell > end.cell);

    while (begin != end) {
        DelIt(begin);
        begin++;
    }
}

template <typename T>
Array<T>& Array<T>::operator + (const T element) {
    PushBack(element);
}

template <typename T>
Array<T>& Array<T>::operator += (const T element) {
    *this = *this + element;
    return *this;
}

template <typename T>
void Array<T>::PushBack(const T& value) {
    Array back;
    back.data = new T[size + 1];
    for (int i = 0; i < size; i++)
        back.datd[i] = data[i];
    back.data[size] = value;
    return back;
}