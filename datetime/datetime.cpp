#include <string>
#include <iostream>
#include <map>
#include "datetime.h"

using namespace std;

bool DateTime::symbolIsDivider(const char symbol)
{
    for (int i = 0; i < dividers.length(); i++)
        if (symbol == dividers[i]) 
            return true;
    return false;
}

unsigned int DateTime::leapYearCount() const
{
    return (this->getYear()-1970) / 4;
}
DateTime::DateTime()
{
    this->seconds = 0;
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
    short day = stoi(date[0]);
    
    short month = 1;
    if (date[1].length() > 2) 
    {
        try { month = hMounth.at(date[1]); }
        catch (out_of_range) 
        { 
            cout << "Month " << date[1] << " doesn't exist!" << endl; 
            throw; 
        }
    }
    else month = stoi(date[1]);

    short year = stoi(date[2]) + 2000*(date[2].length() < 3);
    short hour = stoi(date[3]); 
    short minute = stoi(date[4]);
    short second = stoi(date[5]);

    if (year < 1970) { cout << date_str << ": year should be greater then 1970" << endl; throw; }
    if (month > 12) { cout << date_str << ": month should be less then 13" << endl; throw; }
    if (second > 59) { cout << date_str << ": seconds should be less than 60" << endl; throw; }
    if (minute > 59) { cout << date_str << ": minutes should be less than 60" << endl; throw; }
    if (hour > 23) { cout << date_str << ": hours should be less than 24" << endl; throw; }

    seconds = 365 * (year - 1970) + day; // Добавляем дни относительно прошедших дней
    seconds += (year - 1970) / 4 + (year % 4 == 0 && month > 2); // Добавляем недостающие дни от високосных годов
    for (int i = 0; i < month-1; ++i) seconds += DAYS_IN_MONTH[i];

    seconds *= SECONDS_IN_DAY;

    if (date[3].length() == 0) return;

    seconds += hour * 60*60;
    seconds += minute * 60; 
    seconds += second;
}

DateTime::DateTime(const unsigned long long seconds) 
{
    this->seconds = seconds;
}


int DateTime::getMaxDay(const int year, const int month) 
{
    return DAYS_IN_MONTH[month + (month == 2 && year % 4 == 0)]; 
}


int DateTime::getYear() const 
{
    return this->getDays()/365+1970;
}

int DateTime::getMonth() const 
{
    unsigned int days = this->getDays()%365 - this->leapYearCount();
    int i = 0;
    for (;days > DAYS_IN_MONTH[i]; i++)
    {
        days -= DAYS_IN_MONTH[i];
    }
    return i+1;
}
int DateTime::getDate() const
{
    unsigned int days = this->getDays()%365 - this->leapYearCount();
    int i = 0;
    for (;days > DAYS_IN_MONTH[i]; i++)
    {
        days -= DAYS_IN_MONTH[i];
    }
    return days;
}
int DateTime::getHour() const 
{
    return this->seconds / 60 / 60 % 24;
}
int DateTime::getMinute() const 
{
    return this->seconds / 60 % 60;
}
int DateTime::getSecond() const 
{
    return this->seconds % 60;
}

int DateTime::getDays() const
{
    return this->seconds / SECONDS_IN_DAY;
}

string DateTime::getDayOfWeek()
{
    int days = this->getDays(); 
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

unsigned long long DateTime::operator- (const DateTime& datetime) 
{  
    return this->seconds - datetime.seconds;
}

void print(const DateTime & datetime, const string format)
{
    cout << "Date: ";
    for (int i = 0; i < format.length(); i++) {
        if (format[i] == 'd') cout << datetime.getDate();
        else if (format[i] == 'M') cout << datetime.getMonth();
        else if (format[i] == 'y') cout << datetime.getYear();
        else if (format[i] == 'h') cout << datetime.getHour();
        else if (format[i] == 'm') cout << datetime.getMinute();
        else if (format[i] == 's') cout << datetime.getSecond();
        else cout << format[i];
    }
    cout << endl;
}

void getEasterDate(const int year) 
{
    int a = year % 19, b = year % 4, c = year % 7;

    int d = (19*a + 15) % 30; 
    int e = (2*b + 4*c + 6*d + 6) % 7;

    if (d+e > 9) cout << d+e-9 << ".04." << year << endl;
    else cout << 22+d+e << ".03." << year << endl;
}