#include <iostream>
#include <string>
#include "Plenty.h"

//конструкторы и деструктор
Plenty::Plenty(): BoolVector(size_table, 0) {}

Plenty::Plenty(const char* array): Plenty() {
    for (int i = 0; array[i] != '\0'; i++)
        *this += array[i];
}

Plenty::Plenty(const Plenty& other): BoolVector(other){}

Plenty::~Plenty() {}

//ввод и вывод
void Plenty::Print() const {
    std::cout << "{ ";
    for (int i = 0; i < size_table; i++) 
        if (BitValue(i)) 
            std::cout << static_cast<char>(i + start_table) << " ";
    std::cout << "}\n";
}

void Plenty::Scan() {
    std::string str;
    std::cout << "введите символы: \n";
    std::cin >> str;
    for (int i = 0; i < str.length(); i++)
        if (str[i] >= start_table && str[i] <= end_table)
            Set(1, str[i] - start_table);
}

//проверка наличия элемента в множестве и получение мощности множества
bool Plenty::InPlenty(const char element) const {
    if (element < start_table && element >= end_table)
        return false;
    return BitValue(element - start_table);
}

int Plenty::Capacity() const{
    int count = 0; 
    for (int i = 0; i < size_table; i++)
        if (BitValue(i))
            count++;
    return count;
}

//поиск максимального/минимального элемента множества
char Plenty::MaxElement() const {
    for (int i = size_table - 1; i >= 0; i--)
        if (BitValue(i))
            return static_cast<char>(i + start_table);
}

char Plenty::MinElement() const {
    for (int i = 0; i < size_table; i++)
        if (BitValue(i))
            return static_cast<char>(i + start_table);
}

//перегрузки
Plenty Plenty::operator ~ () const {
    Plenty back(*this);
    back.Inversion();
    return back;
}

Plenty& Plenty::operator = (const Plenty& other) {
    BoolVector::operator = (other);
    return *this;
}

Plenty Plenty::operator | (const Plenty& other) const {
    Plenty back(*this);
    back |= other;
    return back;
}

Plenty& Plenty::operator |= (const Plenty& other) {
    BoolVector::operator|=(other);
    return *this;    
}

Plenty Plenty::operator & (const Plenty& other) const {
    Plenty back(*this);
    back &= other;
    return back;
}

Plenty& Plenty::operator &= (const Plenty& other) {
    BoolVector::operator&=(other);
    return *this;
}

Plenty Plenty::operator / (const Plenty& other) const {
    Plenty back(*this);
    back /= other;
    return back;
}

Plenty& Plenty::operator /= (const Plenty& other) {
    BoolVector::operator&=(~other);
    return *this;
}

Plenty Plenty::operator + (const char value) const {
    Plenty back(*this);
    back += value;
    return back;
}

Plenty& Plenty::operator += (const char value) {
    Set(1, value - start_table);
    return *this;
}

Plenty Plenty::operator - (const char value) const {
    Plenty back(*this);
    back -= value;
    return back;
}

Plenty& Plenty::operator -= (const char value) {
    Set(0, value - start_table);
    return *this;
}

bool Plenty::operator == (const Plenty& other) const {
    return BoolVector::operator == (other);
}

bool Plenty::operator != (const Plenty& other) const {
    return !(*this == other);
}

//потоковый ввод и вывод
std::ostream& operator << (std::ostream& stream, const Plenty& set) {
    stream << "{ ";
    for (int i = 0; i < set.size_table; i++)
        if (set.GetBitBV(i))
            stream << static_cast<char>(i + set.start_table) << " ";
    stream << "}\n";
    return stream;
}

std::istream& operator >> (std::istream& stream, Plenty& set) {
    std::string str;
    stream >> str;
    for (int i = 0; i < str.length(); i++)
        if (str[i] >= set.start_table && str[i] <= set.end_table)
            set.SetBit(1, str[i] - set.start_table);
    return stream;
}

//доп функции
bool Plenty::GetBitBV(const int index) const {
    return BitValue(index);
}

void Plenty::SetBit(const bool bit, const int index) {
    Set(bit, index);
}