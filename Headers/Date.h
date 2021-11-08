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

    ~Date();

    void initializeDate();

    int getDay() const;

    void setDay(int day);

    int getDayOfWeek() const;

    void setDayOfWeek(int dayOfWeek);

    int getMonth() const;

    void setMonth(int month);

    bool isLastDayOfMonth() const;

    bool getIsLeapYear() const;

    int getYear() const;

    void setYear(int year);

    const std::vector<std::string> &getDaysOfWeek() const;

private:
    void verifyLeapYear(int year);

    bool isValidDay(int newDay);

    void setIsLeapYear(bool isLeapYear);


private:
    int day, dayOfWeek, month, year;
    bool isLeapYear;
    bool lastDayOfMonth;
    DateFormat dateFormat;
    const std::vector<std::string> daysOfWeek;

    bool isValidMonth(int newMonth);

    bool isValidYear(int newYear);
};


#endif //TIMER_QT_DATE_H
