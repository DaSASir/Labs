#pragma once
class Fraction {
public:
    Fraction();
    Fraction(const int a, const int b);

    void Scan();
    void Print() const;

    bool IsCorrectness();

    Fraction Addition(const Fraction d2) const;
    Fraction Deduction(const Fraction d2) const;
    Fraction Multiplication(const Fraction d2) const;
    Fraction Division(const Fraction d2) const;

    Fraction operator + (const Fraction d2) const;
    Fraction operator - (const Fraction d2) const;
    Fraction operator * (const Fraction d2) const;
    Fraction operator / (const Fraction d2) const;

    bool operator > (const Fraction d2) const;
    bool operator < (const Fraction d2) const;
    bool operator == (const Fraction d2) const;
    bool operator != (const Fraction d2) const;

    int GetNumerator() const;
    int GetDenominator() const;

    void Cut();
    int GreatestCommonDivisor();

    //собственные функции
    Fraction operator + (const int cheese);
    Fraction operator - (const int cheese);
    void WholePartPrint();

    //установление числителя и знаменателя
    void EstablishmentNumerator(int cheese);
    void EstablishmentDenominator(int cheese);

private:

    int numerator, denominator;
};