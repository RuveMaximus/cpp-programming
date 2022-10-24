#include <iostream>
#include "rational.h"

void Rational::simplify()
{
    int a = this->numerator; 
    int b = a % this->denominator;
    while (b > 0)
    {
        a = b; 
        b = a%b;
    }

    if (a == 0) return;

    this->numerator /= a;
    this->denominator /= a; 
}


Rational::Rational()
{
    numerator = 0; 
    denominator = 1;
}
Rational::Rational(const int& a)
{
    numerator = a; 
    denominator = 1;
}
Rational::Rational(const int& a, const int &b) 
{
    numerator = a; 
    denominator = b;

    simplify();
}


void Rational::show()
{
    std::cout << this->numerator << '/' << this->denominator << std::endl;
}


Rational& Rational::operator += (const Rational& r)
{
    numerator = (numerator*r.denominator + denominator*r.numerator);
    denominator *= r.denominator; 

    simplify();

    return *this;
}