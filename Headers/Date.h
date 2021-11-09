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

    int getDay() const;

    void setDay(int day);

    int getDayOfWeek() const;

    std::string gateDayOfWeekAsString() const;

    void setDayOfWeek(int dayOfWeek);

    int getMonth() const;

    void setMonth(int month);

    bool isLastDayOfMonth() const;

    bool getIsLeapYear() const;

    int getYear() const;

    void setYear(int year);

    void setFullDate(int newDay, int newMonth, int newYear);

    std::string getFullDate();

    void setDateFormat(DateFormat dateFormat);


private:
    void verifyLeapYear(int year);

    bool isValidDay(int newDay);

    void setIsLeapYear(bool isLeapYear);

    bool isValidMonth(int newMonth);

    bool isValidYear(int newYear);

    void setDayOfWeekFromCurrentDate();


    int day, dayOfWeek, month, year;
    bool isLeapYear;
    bool lastDayOfMonth;
    DateFormat dateFormat;
    const std::vector<std::string> daysOfWeek;
};


#endif //TIMER_QT_DATE_H
