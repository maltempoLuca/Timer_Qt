//
// Created by Luca Maltempo on 05/11/21.
//

#ifndef TIMER_QT_DATE_H
#define TIMER_QT_DATE_H

#include <string>
#include <vector>

enum DateFormat {
    YMD, DMY, MDY, ReducedFormat
};

class Date {
public:
    Date();

//    Date(int day, int dayOfWeek, int month, int year, bool isLeapYear, DateFormat dateFormat = DMY);

    ~Date();

    int getDay() const;

    void setDay(int day);

    int getDayOfWeek() const;

    void setDayOfWeek(int dayOfWeek);

    int getMonth() const;

    void setMonth(int month);

    bool getIsLeapYear() const;

    int getYear() const;

    void setYear(int year);

    const std::vector<std::string> &getDaysOfWeek() const;

    bool isNotLastDayOfMonth();

private:
    void verifyLeapYear(int year);

    void setIsLeapYear(bool isLeapYear);

    bool isValidDay(int newDay) const;


private:
    int day, dayOfWeek, month, year;
    bool isLeapYear;
    DateFormat dateFormat;
    const std::vector<std::string> daysOfWeek;
};


#endif //TIMER_QT_DATE_H
