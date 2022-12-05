#include <iostream>
#include "datetime.h"

using namespace std;

int main()
{
    DateTime a("05.12.2022"); 
    DateTime b("06.12.2022");

    a.print();
    b.print();

    cout << a-b << endl;

    return 0;
}