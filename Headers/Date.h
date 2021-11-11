//
// Created by Luca Maltempo on 05/11/21.
//

#ifndef TIMER_QT_DATE_H
#define TIMER_QT_DATE_H

#include <string>
#include <vector>
#include <iostream>


enum DateFormat {
    YMD, DMY, MDY, ReducedFormat
};

class Date {
public:
    Date();

    Date(int day, int month, int year);

    ~Date();

    void initializeDate();

    void setDay(int day);

    void setMonth(int month);

    void setYear(int year);

    void setFullDate(int newDay, int newMonth, int newYear);

    void setDateFormat(DateFormat dateFormat);

    std::string getFullDate() const;

    int getDay() const;

    int getDayOfWeek() const;

    const std::string &gatDayOfWeekAsString() const;

    int getMonth() const;

    bool isLastDayOfMonth() const;

    bool isLeapYear() const;

    int getYear() const;

private:

    void verifyLeapYear(int year);

    bool isValidDay(int newDay);

    bool isValidMonth(int newMonth);

    bool isValidYear(int newYear);

    void setDayOfWeekFromCurrentDate();


    int day, dayOfWeek, month, year;
    bool leapYear;
    bool lastDayOfMonth;
    DateFormat dateFormat;
    const std::vector<std::string> daysOfWeek;
};


#endif //TIMER_QT_DATE_H
