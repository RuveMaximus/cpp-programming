#include <string>
#include <iostream>
#include <map>
#include "datetime.h"

using namespace std;

bool DateTime::symbolIsDivider(const char symbol)
{
    for (int i = 0; i < dividers.length(); i++)
    {
        if (symbol == dividers[i]) return true;
    }
    return false;
}

DateTime::DateTime(const string date_str)
{
    string date[6];
    int currentFormat = 0;
    for (int i = 0; i < date_str.length(); i++)
    {
        if (symbolIsDivider(date_str[i])) currentFormat++;
        else date[currentFormat] += date_str[i];
    }
    short year = stoi(date[2]);
    short month = stoi(date[1]);
    short day = stoi(date[0]);

    days = 365 * (year - 1970) + day; // Добавляем дни относительно прошедших дней
    days += (year - 1970) / 4 + (year % 4 == 0 && month > 2); // Добавляем недостающие дни от високосных годов
    for (int i = 0; i < month-1; ++i) days += DAYS_IN_MONTH[i];
}

DateTime::DateTime(const unsigned long long days) 
{
    this->days = days;
}

void DateTime::print()
{
    cout << days << endl;
}

int DateTime::getMaxDay(const int year, const int month) 
{
    return DAYS_IN_MONTH[month + (month == 2 && year % 4 == 0)]; 
}

string DateTime::getDayOfWeek()
{
    const map <int, string> dayOfWeek = {
        {5, "Mon"},
        {6, "Tue"},
        {0, "Wed"},
        {1, "Thur"},
        {2, "Fri"},
        {3, "Sat"},
        {4, "Sun"},
    };

    return dayOfWeek.at(days % 7);
}

unsigned long long DateTime::operator- (const DateTime& date) 
{  
    return this->days - date.days;
}