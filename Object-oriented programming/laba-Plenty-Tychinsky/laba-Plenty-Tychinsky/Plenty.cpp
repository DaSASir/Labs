#include <iostream>
#include <string>
#include "Plenty.h"

Plenty::Plenty() 
    : BoolVector(size_table,0), size(0) {}

Plenty::Plenty(const char* array) 
    : BoolVector(size_table,0), size(0) {
    for(int i =0 ; i < strlen(array); i++)
        if (!InPlenty(array[i])) {
            elements[size++] = array[i];
            Inversion(i);
        }
}

Plenty::Plenty(const Plenty& other) 
    : BoolVector(other), size(other.size) {
    for (int i = 0; i < size; i++)
        elements[i] = other.elements[i];
}

Plenty::~Plenty() {
    ~BoolVector();
}

void Plenty::Print() const {
    using std::cout;
    cout << "[ ";
    for (int i = 0; i < size; i++)
        cout << elements[i] << " ";
    cout << "]" << std::endl;
}

void Plenty::Scan() {
    std::string s;
    std::cout << "Введите символы: ";
    std::cin >> s;

    size = 0;

    for (int i = 0; i < s.length(); i++)
        if (!InPlenty(s[i]))
            elements[size++] = s[i];
}

bool Plenty::InPlenty(const char element) const {
    for (int i = 0; i < size; i++)
        if (elements[i] == element)
            return true;

    return false;
}

char Plenty::MaxElement() const {
    if (size == 0)
        return '\0';

    char max = elements[0];
    for (int i = 1; i < size; i++)
        if (max < elements[i])
            max = elements[i];

    return max;
}

char Plenty::MinElement() const {
    if (size == 0)
        return '\0';

    char min = elements[0];
    for (int i = 1; i < size; i++)
        if (min > elements[i])
            min = elements[i];

    return min;
}

int Plenty::Capacity() {
    return size;
}

Plenty Plenty::operator=(const Plenty& other) {
    if (this != &other) {
        BoolVector::operator=(other);
        size = other.size;
        for (int i = 0; i < size; i++)
            elements[i] = other.elements[i];
    }
    
    return *this;
}

bool Plenty::operator==(const Plenty& other) {
    return BoolVector::operator==(other);
}

bool Plenty::operator!=(const Plenty& other) {
    return !(*this == other);
}

Plenty Plenty::operator|(const Plenty& other) const {
    Plenty back = *this;
    for (int i = 0; i < other.size; i++)
        if (!InPlenty(other.elements[i]) && back.size < size_table) {
            back.elements[back.size++] = other.elements[i];
            back.Inversion(i);
        }

    return back;
}

Plenty Plenty::operator|=(const Plenty& other) {
    *this = *this | other;
    return *this;
}

Plenty Plenty::operator&(const Plenty& other) const {
    Plenty back;
    for (int i = 0; i < other.size; i++)
        if (InPlenty(other.elements[i])) 
            back.elements[back.size++] = elements[i];

    return back;
}

Plenty Plenty::operator&=(const Plenty& other) {
    *this = *this & other;
    return *this;
}

Plenty Plenty::operator/(const Plenty& other) const {
    Plenty back;
    for (int i = 0; i < other.size; i++)
        if (!InPlenty(other.elements[i]))
            back.elements[back.size++] = elements[i];

    return back;
}

Plenty Plenty::operator/=(const Plenty& other) {
    *this = *this / other;
    return *this;
}

Plenty Plenty::operator~() {
    Plenty back;
    for (char el = start_table; el < size_table; el++)
        if (!InPlenty(el)) {
            back.elements[back.size++] = el;
            back.Inversion((int)el);
        }
   
    return back;
}

Plenty Plenty::operator+(const char value) const {
    Plenty back = *this;
    if (!InPlenty(value)) {
        back.elements[back.size++] = value;
        back.Inversion((int)value);
    }
    return back;
}

Plenty Plenty::operator+=(const char value) {
    *this = *this + value;
    return *this;
}

Plenty Plenty::operator-(const char value) const {
    Plenty back;
    for (int i = 0; i < size; i++) 
        if (elements[i] != value) {
            back.elements[back.size++] = elements[i];
            back.Inversion(i);
        }
            
    return back;
}

Plenty Plenty::operator-=(const char value) {
    *this = *this - value;
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Plenty& other) {
    stream << "{ ";
    for (int i = 0; i < other.size; i++) 
        stream << other.elements[i] << " ";

    stream << "}";
    return stream;
}

std::istream& operator>>(std::istream& stream, Plenty& other) {
    std::string s;
    stream >> s;

    other.size = 0;

    for (int i = 0; i < s.length(); i++)
        if (!other.InPlenty(s[i]))
            other.elements[other.size++] = s[i];
}