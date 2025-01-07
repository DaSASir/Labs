#include <iostream>
#include "Fraction.h"

Fraction::Fraction ()
    : m_numerator(1), m_denominator(1) { }

Fraction::Fraction(const int numerator, const int denominator) 
    : m_numerator(numerator), m_denominator(denominator) {
    if (!IsCorrectness())
        m_denominator = 1;
}

void Fraction::SetNumerator(const int value) {
    m_numerator = value;
}
void Fraction::SetDenominator(const int value) {
    m_denominator = value;
    if (!IsCorrectness())
        m_denominator = 1;
}
int Fraction::GetNumerator() const {
    return m_numerator;
}
int Fraction::GetDenominator() const {
    return m_denominator;
}

Fraction Fraction::Addition(const Fraction other) const {
    Fraction back;
    back.m_denominator = m_denominator * other.m_denominator;
    back.m_numerator = m_numerator * other.m_denominator + other.m_numerator * m_denominator;
    back.Cut();
    return back;
}
Fraction Fraction::Deduction(const Fraction other) const {
    Fraction back;
    if (other > *this) {
        back.m_denominator = m_denominator * other.m_denominator;
        back.m_numerator = (other.m_numerator * m_denominator - m_numerator * other.m_denominator) * (-1);
    }
    else {
        back.m_denominator = m_denominator * other.m_denominator;
        back.m_numerator = m_numerator * other.m_denominator - other.m_numerator * m_denominator;
    }
    back.Cut();
    return back;
}
Fraction Fraction::Multiplication(const Fraction other) const {
    Fraction back;
    back.m_numerator = m_numerator * other.m_numerator;
    back.m_denominator = m_denominator * other.m_denominator;
    back.Cut();
    return back;
}
Fraction Fraction::Division(const Fraction other) const {
    Fraction back;
    back.m_numerator = m_numerator * other.m_denominator;
    back.m_denominator = m_denominator * other.m_numerator;
    back.Cut();
    return back;
}

Fraction Fraction::operator + (const Fraction other) const {
    return Addition(other);
}
Fraction Fraction::operator - (const Fraction other) const {
    return Deduction(other);
}
Fraction Fraction::operator * (const Fraction other) const {
    return Multiplication(other);
}
Fraction Fraction::operator / (const Fraction other) const {
    return Division(other);
}

bool Fraction::operator > (const Fraction other) const {
    return ((m_numerator * other.m_denominator) > (other.m_numerator * m_denominator));
}
bool Fraction::operator < (const Fraction other) const {
    return !(operator > (other));
}
bool Fraction::operator == (const Fraction other) const {
    return (m_numerator == other.m_numerator && m_denominator == other.m_denominator);
}
bool Fraction::operator != (const Fraction other) const {
    return !(operator == (other));
}

void Fraction::Cut() {
    int nod = GreatestCommonDivisor();
    m_numerator /= nod;
    m_denominator /= nod;
}

int Fraction::GreatestCommonDivisor() const{
    int value1 = m_numerator,
        value2 = m_denominator;

    if (value1 < 0)
        value1 *= (-1);

    if (value2 < 0)
        value2 *= (-1);

    while (value1 && value2)
        (value1 > value2) ? value1 %= value2 : value2 %= value1;

    return (value1 + value2);
}

void Fraction::Scan() {
    using std::cout;
    using std::cin;

    cout << "Введите числитель: ";
    cin >> m_numerator;

    cout << "Введите знаменатель: ";
    cin >> m_denominator;

    while (!IsCorrectness()) {
        cout << "Введите знаменатель не равный 0: ";
        cin >> m_denominator;
    }
}
void Fraction::Print() const {
    std::cout << m_numerator << "/" << m_denominator << std::endl;
}

bool Fraction::IsCorrectness() const{
    return !(m_denominator == 0);
}

Fraction Fraction::operator + (const int value) {
    Fraction CH(value, 1), back;
    back = this->Addition(CH);
    return back;
}
Fraction Fraction::operator - (const int value) {
    Fraction CH(value, 1), back;
    back = this->Deduction(CH);
    return back;
}
void Fraction::WholePartPrint() {
    int wholepart = 0, 
        numerator = m_numerator,
        denominator = m_denominator;

    if (numerator < denominator)
        std::cout << "Дробь не может иметь целочисленные значения!";

    while (numerator > denominator) {
        numerator -= denominator;
        wholepart++;
    }

    std::cout << "Дробь с целочисленными значения выглядит так: " << wholepart << " " << numerator << "/" << denominator;
}
