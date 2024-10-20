#include <iostream>
#include "Fraction.h"

using namespace std;

Fraction::Fraction (): numerator(1), denominator(1) { }
Fraction::Fraction(const int a, const int b) : numerator(a), denominator(b) {
    if (!IsCorrectness())
        denominator = 1;
}

void Fraction::Scan() {
    system("chcp 1251");
    cout << "¬ведите числитель: ";
    cin >> numerator;
    cout << "¬ведите знаменатель: ";
    cin >> denominator;
    while (!IsCorrectness()) {
        cout << "¬ведите знаменатель не равный 0: ";
        cin >> denominator;
    }
}
void Fraction::Print() const {
    cout << numerator << "/" << denominator << endl;
}

bool Fraction::IsCorrectness() {
    return !(denominator == 0);
}

Fraction Fraction::Addition(const Fraction d2) const {
    Fraction d3;
    d3.denominator = denominator * d2.denominator;
    d3.numerator = numerator * d2.denominator + d2.numerator * denominator;
    d3.Cut();
    return d3;
}
Fraction Fraction::Deduction(const Fraction d2) const {
    Fraction d3, d4 = d2;
    if (d4 > *this) {
        d3.denominator = denominator * d2.denominator;
        d3.numerator = (d2.numerator * denominator - numerator * d2.denominator) * (-1);
    }
    else {
        d3.denominator = denominator * d2.denominator;
        d3.numerator = numerator * d2.denominator - d2.numerator * denominator;
    }
    d3.Cut();
    return d3;
}
Fraction Fraction::Multiplication(const Fraction d2) const {
    Fraction d3;
    d3.numerator = numerator * d2.numerator;
    d3.denominator = denominator * d2.denominator;
    d3.Cut();
    return d3;
}
Fraction Fraction::Division(const Fraction d2) const {
    Fraction d3;
    d3.numerator = numerator * d2.denominator;
    d3.denominator = denominator * d2.numerator;
    d3.Cut();
    return d3;
}

Fraction Fraction::operator + (const Fraction d2) const {
    return Addition(d2);
}
Fraction Fraction::operator - (const Fraction d2) const {
    return Deduction(d2);
}
Fraction Fraction::operator * (const Fraction d2) const {
    return Multiplication(d2);
}
Fraction Fraction::operator / (const Fraction d2) const {
    return Division(d2);
}

bool Fraction::operator > (const Fraction d2) const {
    return ((numerator * d2.denominator) > (d2.numerator * denominator));
}
bool Fraction::operator < (const Fraction d2) const {
    return !(operator > (d2));
}
bool Fraction::operator == (const Fraction d2) const {
    return numerator == d2.numerator && denominator == d2.denominator;
}
bool Fraction::operator != (const Fraction d2) const{
    return !(operator == (d2));
}

int Fraction::GetNumerator() const {
    return numerator;
}
int Fraction::GetDenominator() const {
    return denominator;
}

void Fraction::Cut() {
    int nod = GreatestCommonDivisor();
    numerator /= nod;
    denominator /= nod;
}

int Fraction::GreatestCommonDivisor() {
    int c1 = numerator, c2 = denominator;
    if (c1 < 0)
        c1 *= (-1);
    if (c2 < 0)
        c2 *= (-1);
    while (c1 && c2) {
        if (c1 > c2)
            c1 %= c2;
        else c2 %= c1;
    }return c1 + c2;
}

Fraction Fraction::operator + (const int cheese) {
    Fraction CH(cheese, 1), d3;
    d3 = this->Addition(CH);
    return d3;
}
Fraction Fraction::operator - (const int cheese) {
    Fraction CH(cheese, 1), d3;
    d3 = this->Deduction(CH);
    return d3;
}
void Fraction::WholePartPrint() {
    system("chcp 1251");
    int wholepart = 0, ch = numerator, zn = denominator;
    if (ch < zn) cout << "ƒробь не может иметь целочисленные значени€!";
    while (ch > zn) {
        ch -= zn;
        wholepart++;
    }
    cout << "ƒробь с целочисленными значени€ выгл€дит так: " << wholepart << " " << ch << "/" << zn;
}

//установление
void Fraction::EstablishmentNumerator(int cheese) {
    numerator = cheese;
}
void Fraction::EstablishmentDenominator(int cheese) {
    denominator = cheese;
}
