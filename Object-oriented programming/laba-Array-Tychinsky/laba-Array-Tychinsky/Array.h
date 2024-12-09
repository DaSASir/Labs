#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <assert.h>

template <typename T>
class Array {
public:
    //----------<YELLOW>----------
    Array();
    Array(const T* arr, int n);
    Array(const Array& other);
    ~Array();

    int GetSize() const;
    //получение размера (количества хранимых элементов в настоящий момент)
    void Swap(Array& other);
    //обмен содержимого с другим массивом
    int Find(const T& value) const;
    //поиск элемента(возвращает индекс первого совпавшего элемента,
    // либо - 1, если совпадений нет)
    void Print() const;
    void Scan();
    //ввод/вывод в консоль
    void Sorting();
    //сортировка элементов(любым алгоритмом)
    bool Insert(int index, const T& value);
    //вставка элемента по индексу. Если индекс некорректный, вернуть false
    bool DelIndex(int index);
    //удаление элемента по индексу. Если индекс некорректный, вернуть false
    bool DelValue(const T& value);
    //удаление элемента по значению (первое вхождение). 
    //Если элемент отсутствует в массиве, вернуть false
    T& operator[](int index);
    const T& operator[](int index) const;
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
    private:
        T* cell;
    public:
        Iterator(T* c);
        T& operator*();
        Iterator& operator++();
        Iterator operator++(int);
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
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
    T* data;
    int size;
};

#include "Array.cpp" 

#endif