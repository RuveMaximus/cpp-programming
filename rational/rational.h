#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
public:
    int numerator;
    int denominator;

    Rational();
    Rational(const int&);
    Rational(const int&, const int&);

    void show();

    Rational& operator +=(const Rational& r);

private:
    void simplify();
};

#endif