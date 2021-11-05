//
// Created by Luca Maltempo on 05/11/21.
//

#ifndef TIMER_QT_DATE_H
#define TIMER_QT_DATE_H

#include <string>

enum DateFormat {
    YMD, DMY, MDY, ReducedFormat
};

class Date {
public:
    Date(int day, int dayOfWeek, int month, int year, bool isLeapYear, DateFormat dateFormat = DMY);

    ~Date();

    int getDay() const;

    void setDay(int day);

    int getDayOfWeek() const;

    void setDayOfWeek(int dayOfWeek);

    int getMonth() const;

    void setMonth(int month);

    int getYear() const;

    void setYear(int year);

    bool isLeapYear1() const;

    void setIsLeapYear(bool isLeapYear);


private:
    int day, dayOfWeek, month, year;
    bool isLeapYear;
    DateFormat dateFormat;
    std::string daysOfWeek[7] = {"Monday", "Tuesday", "Wednesday",
                                 "Thursday", "Friday", "Saturday",
                                 "Sunday"};
};


#endif //TIMER_QT_DATE_H
