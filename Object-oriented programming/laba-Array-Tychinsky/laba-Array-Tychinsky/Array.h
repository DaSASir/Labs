#include <iostream>
#include <assert.h>

template <typename T>
class Array {
public:
    typedef T* Iterator;

    Array();
    Array(const int size);
    Array(T* array, const int size);
    Array(const Array<T>& other);
    ~Array();

    void Print() const;
    void Scan();

    int GetSize() const;
    T GetMax() const;
    T GetMin() const;

    void Swap(Array<T>& other);
    int FindElement(const T& value) const;

    void Sorting();

    bool AddIndex(const int index, const T& value);

    bool DelIndex(const int index);
    bool DelValue(const T& value);
    void DelAll(const T& value);

    Iterator begin();
    Iterator end();
    const Iterator begin() const;
    const Iterator end() const;

    void AddIt(Iterator it, const T& value);
    void DelIt(const Iterator it);
    void DelItRange(const Iterator begin, const Iterator end);
    
    T& operator[](const int index);
    const T& operator[](const int index) const;
    Array<T> operator + (const Array<T>& other) const;
    Array<T> operator + (const T element) const;
    Array<T>& operator += (const Array<T>& other);
    Array<T>& operator += (const T element);
    Array<T>& operator = (const Array<T>& other);
    bool operator == (const Array<T>& other) const;
    bool operator != (const Array<T>& other) const;

private:
    T* m_data = nullptr;
    int m_size = 0;
};

//конструкторы и деструктор
template <typename T>
Array<T>::Array() {}

template <typename T>
Array<T>::Array(const int size) : m_size(size) {
    m_data = new T[m_size];
}

template <typename T>
Array<T>::Array(T* array, const int size) : m_size(size) {
    m_data = new T[m_size];
    for (int i = 0; i < m_size; i++)
        m_data[i] = array[i];
}

template <typename T>
Array<T>::Array(const Array<T>& other) : m_size(other.m_size) {
    m_data = new T[m_size];
    for (int i = 0; i < m_size; i++)
        m_data[i] = other.m_data[i];
}

template <typename T>
Array<T>::~Array() {
    delete[] m_data;
}

//ввод и вывод
template <typename T>
void Array<T>::Print() const {
    using std::cout;
    cout << "{ ";
    for (int i = 0; i < m_size; i++)
        cout << m_data[i] << " ";
    cout << "}\n";
}

template <typename T>
void Array<T>::Scan() {
    std::cout << "Введите кол-во элементов: ";
    std::cin >> m_size;

    delete[] m_data;
    m_data = new T[m_size];

    std::cout << "Введите элементы:\n";
    for (int i = 0; i < m_size; i++)
        std::cin >> m_data[i];
}

//получение размера, максимального и минимального элемента
template <typename T>
int Array<T>::GetSize() const {
    return m_size;
}

template <typename T>
T Array<T>::GetMax() const {
    T max = m_data[0];
    for (int i = 1; i < m_size; i++)
        if (m_data[i] > max) max = m_data[i];
    return max;
}

template <typename T>
T Array<T>::GetMin() const {
    T min = m_data[0];
    for (int i = 1; i < m_size; i++)
        if (m_data[i] < min) min = m_data[i];
    return min;
}

//обмен массивов и посик элемента
template <typename T>
void Array<T>::Swap(Array<T>& other) {
    std::swap(m_size, other.m_size);
    std::swap(m_data, other.m_data);
}

template <typename T>
int Array<T>::FindElement(const T& value) const {
    for (int i = 0; i < m_size; i++)
        if (m_data[i] == value) return i;
    return -1;
}

//сортировка и добавление элемента по индексу
template <typename T>
void Array<T>::Sorting() {
    for (int i = 0; i < m_size - 1; i++) {
        bool check = 0;
        for (int j = 0; j < m_size - i - 1; j++)
            if (m_data[j] > m_data[j + 1]) {
                check = 1;
                std::swap(m_data[j], m_data[j + 1]);
            }
        if (check == 0) break;
    }
}

template <typename T>
bool Array<T>::AddIndex(const int index, const T& value) {
    if (index < 0 || index >= m_size) return false;
    T* back = new T[m_size + 1];

    for (int i = 0; i < index; i++)
        back[i] = m_data[i];

    back[index] = value;

    for (int i = index + 1; i < m_size + 1; i++)
        back[i] = m_data[i - 1];

    delete[] m_data;
    m_data = back;
    delete[] back;

    m_size++;

    return true;
}

//удаление элемента по индексу, значению и всех значений
template <typename T>
bool Array<T>::DelIndex(const int index) {
    if (index < 0 || index >= m_size) return false;

    T* back = new T[m_size - 1];

    for (int i = 0; i < index; i++) 
        back[i] = m_data[i];
    for (int i = index + 1; i < m_size; i++) 
        back[i - 1] = m_data[i];

    delete[] m_data;
    m_data = back;
    delete[] back;

    m_size--;

    return true;
}

template <typename T>
bool Array<T>::DelValue(const T& value) {
    return DelIndex(FindElement(value));
}

template <typename T>
void Array<T>::DelAll(const T& value) {
    while (FindElement(value) != -1) 
        DelIndex(FindElement(value));
}

//начальный и последний итератор
template <typename T>
typename Array<T>::Iterator Array<T>::begin() {
    return m_data;
}

template <typename T>
typename Array<T>::Iterator Array<T>::end() {
    return m_data + m_size;
}

template <typename T>
const typename Array<T>::Iterator Array<T>::begin() const {
    return m_data;
}

template <typename T>
const typename Array<T>::Iterator Array<T>::end() const {
    return m_data + m_size;
}

//добавление и удаление по итератору
template <typename T>
void Array<T>::AddIt(Iterator it, const T& value) {
    assert(it >= begin() && it < end());
    AddIndex(it - begin(), value);
}

template <typename T>
void Array<T>::DelIt(const Iterator it) {
    assert(it >= begin() && it < end());
    DelIndex(it - begin());
}

template <typename T>
void Array<T>::DelItRange(const Iterator begin, const Iterator end) {
    assert(begin < end);

    Array<T> trash(end - begin);

    for (int i = 0; i < (end - begin); i++)
        trash[i] = *(begin + i);

    for (int i = 0; i < trash.GetSize(); i++)
        DelValue(trash[i]);
}

//перегрузки
template <typename T>
T& Array<T>::operator[](const int index) {
    return m_data[index];
}

template <typename T>
const T& Array<T>::operator[](const int index) const {
    return m_data[index];
}

template <typename T>
Array<T> Array<T>::operator + (const Array<T>& other) const {
    Array<T> back(m_size + other.m_size);

    for (int i = 0; i < m_size; i++)
        back.m_data[i] = m_data[i];
    for (int i = 0; i < other.m_size; i++)
        back.m_data[i + m_size] = other.m_data[i];

    return back;
}

template <typename T>
Array<T> Array<T>::operator + (const T element) const {
    Array<T> back(m_size + 1);
    
    for (int i = 0; i < m_size; i++)
        back.m_data[i] = m_data[i];
    back.m_data[m_size] = element;

    return back;
}

template <typename T>
Array<T>& Array<T>::operator += (const Array<T>& other) {
    *this = *this + other;
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator += (const T element) {
    *this = *this + element;
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator = (const Array<T>& other) {
    if (*this == other) return *this;

    if (m_size != other.m_size) {
        m_size = other.m_size;

        delete[] m_data;
        m_data = new T[m_size];
    }

    for (int i = 0; i < m_size; i++)
        m_data[i] = other.m_data[i];

    return *this;
}

template <typename T>
bool Array<T>::operator == (const Array<T>& other) const {
    if (m_size != other.m_size) return false;

    for (int i = 0; i < m_size; i++)
        if (m_data[i] != other.m_data[i])
            return false;

    return true;
}

template <typename T>
bool Array<T>::operator != (const Array<T>& other) const {
    return !(*this == other);
}

//потоковый ввод и вывод
template <typename T>
std::ostream& operator<<(std::ostream& stream, const Array<T>& array) {
    stream << "{ ";
    for (int i = 0; i < array.GetSize(); i++) 
        stream << array[i] << " ";

    stream << "}\n";
    return stream;
}

template <typename T>
std::istream& operator>>(std::istream& stream, const Array<T>& array) {
    for (int i = 0; i < array.GetSize(); i++) 
        stream >> array[i];
    
    return stream;
}