#include <iostream>
#include <assert.h>

template <typename T>
class Array {
public:
    //----------<YELLOW>----------
    Array();
    Array(const T* array, const size_t size_a);
    Array(const Array& other);
    ~Array();

    size_t GetSize() const;
    //получение размера (количества хранимых элементов в настоящий момент)
    void Swap(Array& other);
    //обмен содержимого с другим массивом
    size_t Find(const T& value) const;
    //поиск элемента(возвращает индекс первого совпавшего элемента,
    // либо - 1, если совпадений нет)
    void Print() const;
    void Scan();
    //ввод/вывод в консоль
    void Sorting();
    //сортировка элементов(любым алгоритмом)
    bool Insert(size_t index, const T& value);
    //вставка элемента по индексу. Если индекс некорректный, вернуть false
    bool DelIndex(int index);
    //удаление элемента по индексу. Если индекс некорректный, вернуть false
    bool DelValue(const T& value);
    //удаление элемента по значению (первое вхождение). 
    //Если элемент отсутствует в массиве, вернуть false
    T& operator[](int index);
    const T& operator[](const int index) const;
    //получение ссылки на элемент по индексу ([ ])
    Array& operator=(const Array& other);
    //присваивание (=)

    
    //----------<GREEN>----------
    void DelAll(const T& value);
    //удаление всех элементов с заданным значением
    T GetMax() const;
    T GetMin() const;
    //поиск максимального/минимального элемента
    Array& operator + (const Array& other);
    Array& operator += (const Array& other);
    //сложение (конкатенация) с другим массивом 
    //(здесь имеется в виду другим объектом нашего класса, а не стандартные массивы) (+ и +=);
    bool operator == (const Array& other);
    bool operator != (const Array& other);
    //сравнение (== и !=)

    //----------<NO COLOR>----------
    class Iterator {
    public:
        Iterator(T* object = nullptr)
            : m_numbers(object) {}

        T& operator * () {
            return *m_cell;
        }

        Iterator& operator ++ () {
            m_cell++;
            return *this;
        }
        Iterator operator ++ (int) {
            Iterator old(*this);
            m_cell++;
            return *this;
        }
        Iterator& operator -- () {
            m_cell--;
            return *this;
        }
        Iterator operator -- (int) {
            Iterator old(*this);
            m_cell--;
            return *this;
        }
        bool operator == (const Iterator& object) const {
            return m_cell == other.m_cell;
        }
        bool operator != (const Iterator& object) const {
            return m_cell != other.m_cell;
        }
    private:
        T* m_cell;
    };

    //класс итератор
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Array<U>& array);
    template <typename U>
    friend std::istream& operator>>(std::istream& is, const Array<U>& array);
    //потоковый ввод/вывод
    Iterator begin();
    Iterator end();
    // получение итераторов на начало/конец массива (методы должны называться begin и end.
    // Метод end должен возвращать итератор не на последний элемент, а за позицию после него)
    void InsertIt(Iterator it, const T& value);
    //вставка элемента перед итератором
    void DelIt();
    void DelItRange(const Iterator begin, const Iterator end);
    //удаление элемента или диапазона элементов с помощью итераторов
    Array& operator + (const T element);
    Array& operator += (const T element);
    //добавление элемента в конец массива (+ и +=)



    //Доп функции
    void PushBack(const T& value);
    
    


private:
    T* m_data = nullptr;
    size_t m_size = 0;
};

//yellow
template <typename T>
Array<T>::Array(){}

template <typename T>
Array<T>::Array(const T* array, const size_t size_a):m_size(size_a) {
    m_data = new T[m_size];
    for (int i = 0; i < m_size; i++)
        m_data[i] = array[i];
}

template <typename T>
Array<T>::Array(const Array& other)
    : m_data(other.m_data), m_size(other.m_size) {}

template <typename T>
Array<T>::~Array() {
    delete[] m_data;
}

template <typename T>
size_t Array<T>::GetSize() const {
    return m_size;
}

template <typename T>
void Array<T>::Swap(Array& other) {
    using std::swap;
    swap(m_size, other.m_size);
    swap(m_data, other.m_data);
}

template <typename T>
size_t Array<T>::Find(const T& value) const {
    for(int i = 0; i < m_size; i ++)
        if (m_data[i] == value)
            return i;
        
    return -1;
}

template <typename T>
void Array<T>::Print() const {
    using std::cout;
    cout << "\n[ ";
    for (int i = 0; i < m_size; i++)
        cout << m_data[i] << " ";
    cout << "]\n";
}

template <typename T>
void Array<T>::Scan() {
    delete[] m_data;
    std::cout << "Введите кол-во элементов: ";
    std::cin >> m_size;
    m_data = new T[m_size];

    std::cout << "Введите элементы: \n";
    for (int i = 0; i < m_size; i++)
        std::cin >> m_data[i];
}

template <typename T>
void Array<T>::Sorting() {
    for (int i = 0; i < m_size - 1; i++) {
        bool check = 0;
        for (int j = 0; j < m_size - i - 1; j++)
            if (m_data[j] > m_data[j + 1]) {
                check = 1; 
                std::swap(m_data[j], m_data[j + 1]); 
            }
        if (!check) break;
    }
}

template <typename T>
bool Array<T>::Insert(size_t index, const T& value) {
    if (index < 0 || index >= m_size) return -1;
    m_data[index] = value;
}

template <typename T>
bool Array<T>::DelIndex(int index) {
    if (index < 0 || index >= m_size) return -1;

    T* back = new T[m_size - 1];
    for (int i = 0, j = 0; i < m_size; i++)
        if (i != index)
            back[j++] = m_data[i];

    delete[]m_data;
    m_data = back;
    m_size--;
}

template <typename T>
bool Array<T>::DelValue(const T& value) {
    int index = -1;
    for(int i =0;i < m_size;i++)
        if (m_data[i] == value) {
            index = i;
            break;
        }

    if (index == -1) return -1;

    T* back = new T[m_size - 1];
    for (int i = 0, j = 0; i < m_size; i++)
        if (i != index)
            back[j++] = m_data[i];

    delete[]m_data;
    m_data = back;
    m_size--;
}

template <typename T>
T& Array<T>::operator[](int index) {
    assert(index >= 0 || index < m_size);
    return m_data[index];
}

template <typename T>
const T& Array<T>::operator[](const int index) const {
    assert(index >= 0 || index < m_size);
    return m_data[index];
}

template <typename T>
Array<T>& Array<T>::operator = (const Array& other) {
    size = other.m_size;
    delete[] m_data;
    m_data = new T[m_size];
    for (int i = 0; i < m_size; i++)
        m_data[i] = other.m_data[i];
}

//green
template <typename T>
void Array<T>::DelAll(const T& value) {
    int count = 0;
    for (int i = 0; i < m_size; i++)
        if (m_data[i] == value)
            count++;

    for (int i = 0; i < count; i++)
        DelValue(value);
}

template <typename T>
T Array<T>::GetMax() const {
    T max = m_data[0];
    for (int i = 1; i < m_size; i++)
        if (max < m_data[i])
            max = m_data[i];
    return max;
}

template <typename T>
T Array<T>::GetMin() const {
    T min = m_data[0];
    for (int i = 1; i < m_size; i++)
        if (min > m_data[i])
            min = m_data[i];
    return min;
}

template <typename T>
Array<T>& Array<T>::operator + (const Array& other) {
    size_t size2 = m_size + other.m_size;

    T* temp = new T[size2];
    for (int i = 0, j = 0; i < size2; i++) {
        if (i < m_size)
            temp[i] = m_data[i];
        else
            temp[i] = other.m_data[j++];
    }

    Array<T> back(temp, size2);
    return back;
}

template <typename T>
Array<T>& Array<T>::operator += (const Array& other) {
    *this = *this + other;
    return *this;
}

template <typename T>
bool Array<T>::operator == (const Array& other) {
    if (m_size != other.m_size) return false;

    for (int i = 0; i < m_size; i++)
        if (m_data[i] != other.m_data[i])
            return false;

    return true;
}

template <typename T>
bool Array<T>::operator != (const Array& other) {
    return !(*this == other);
}

//no color
template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& array) {
    os << "[ ";
    for (int i = 0; i < array.GetSize(); i++)
        os << array[i] << " ";
    os << "]";
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, const Array<T>& array) {
    for (int i = 0; i < array.GetSize(); i++)
        is >> array[i];
    return is;
}

template <typename T>
Iterator begin() {

}

template <typename T>
Iterator end() {

}

template <typename T>
void InsertIt(Iterator it, const T& value) {

}

template <typename T>
void DelIt() {

}

template <typename T>
void DelItRange(const Iterator begin, const Iterator end) {

}

template <typename T>
Array& operator + (const T element) {

}

template <typename T>
Array& operator += (const T element) {

}
