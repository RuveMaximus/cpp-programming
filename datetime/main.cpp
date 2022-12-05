#include <iostream>
#include "datetime.h"

using namespace std;

int main()
{
    DateTime a("05.12.2022"); 
    DateTime b("05.01.2023");

    a.print();
    b.print();

    cout << b-a << endl;

    DateTime c("6 Nov 14");

    c.print();

    return 0;
}