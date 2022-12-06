#include <iostream>
#include "datetime.h"

using namespace std;

int main()
{
    DateTime a("05.13.2022T22:15:20"); 

    print(a, "h:m:s d-M-y");

    cout << "Days since 01.01.1970: " << a.getDays() << endl;
    cout << "Day of Week: " << a.getDayOfWeek() << endl;
    cout << "Number of leap year since 1970: " << a.leapYearCount() << endl;

    cout << "-----------------" << endl;

    DateTime b("6-12-22T15:20:59");
    print(b, "h:m d.M");

    cout << "Days since 01.01.1970: " << b.getDays() << endl;
    cout << "Day of Week: " << b.getDayOfWeek() << endl;
    cout << "Number of leap year since 1970: " << b.leapYearCount() << endl;

    cout << "-----------------" << endl;

    cout << "Delta time: " << b-a << endl;

    cout << "-----------------" << endl;

    cout << "Easter: ";
    getEasterDate(2006);

    return 0;
}