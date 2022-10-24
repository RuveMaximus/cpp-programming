#include "rational.h"

int main() 
{
    Rational r1(2, 2);
    Rational r2(12, 2);
    r1 += r2;
    r1.show();
}