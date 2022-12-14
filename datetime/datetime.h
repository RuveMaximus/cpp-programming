#ifndef DATETIME_H
#define DATETIME_H

#include <map>
#include <string>
#include <iostream>

const std::string dividers = "T:-. ";

const int SECONDS_IN_DAY = 60*60*24; 
const int DAYS_IN_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const std::map <std::string, int> hMounth = {
    {"Jan", 1},
    {"Feb", 2},
    {"Mar", 3},
    {"Apr", 4},
    {"May", 5},
    {"Jun", 6},
    {"Jul", 7},
    {"Aug", 8},
    {"Sep", 9},
    {"Oct", 10},
    {"Nov", 11},
    {"Dec", 12},
};

class DateTime
{
private:
    unsigned long long seconds;
    bool symbolIsDivider(const char); 

public:
    DateTime();
    DateTime(const std::string);
    DateTime(const unsigned long long);
    
    int getMaxDay(const int, const int); 
    unsigned int leapYearCount() const; // число високосных годов с 1970

    int getYear() const;
    int getMonth() const;
    int getDate() const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    int getDays() const;
    std::string getDayOfWeek();

    unsigned long long operator- (const DateTime&);
    friend void print(const DateTime&, const std::string);
};

void getEasterDate(const int);

#endif