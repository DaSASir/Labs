#pragma once
class Fraction {
public:
    Fraction();
    Fraction(const int a, const int b);

    void Scan();
    void Print() const;

    bool Checking_for_correctness();

    Fraction Addition(const Fraction d2) const;
    Fraction Deduction(const Fraction d2) const;
    Fraction Multiplication(const Fraction d2) const;
    Fraction Division(const Fraction d2) const;

    Fraction operator + (const Fraction d2);
    Fraction operator - (const Fraction d2);
    Fraction operator * (const Fraction d2);
    Fraction operator / (const Fraction d2);

    bool operator > (const Fraction d2);
    bool operator < (const Fraction d2);
    bool operator == (const Fraction d2);
    bool operator != (const Fraction d2);

    int GiveMeNumerator() const;
    int GiveMeDenominator() const;

    void cutting();
    int NOD();

    //собственные функции
    Fraction operator + (const int cheese);
    Fraction operator - (const int cheese);
    void WholePartPrint();

private:

    int numerator, denominator;
};