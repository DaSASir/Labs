#pragma once

class Fraction {
public:
    Fraction();
    Fraction(const int numerator, const int denominator);

    void SetNumerator(const int value);
    void SetDenominator(const int value);
    int GetNumerator() const;
    int GetDenominator() const;

    Fraction Addition(const Fraction other) const;
    Fraction Deduction(const Fraction other) const;
    Fraction Multiplication(const Fraction other) const;
    Fraction Division(const Fraction other) const;

    Fraction operator + (const Fraction other) const;
    Fraction operator - (const Fraction other) const;
    Fraction operator * (const Fraction other) const;
    Fraction operator / (const Fraction other) const;

    bool operator > (const Fraction other) const;
    bool operator < (const Fraction other) const;
    bool operator == (const Fraction other) const;
    bool operator != (const Fraction other) const;

    void Cut();
    int GreatestCommonDivisor() const;

    void Scan();
    void Print() const;

    bool IsCorrectness() const;

    //собственные функции
    Fraction operator + (const int value);
    Fraction operator - (const int value);
    void WholePartPrint();

private:
    int m_numerator,
        m_denominator;

};