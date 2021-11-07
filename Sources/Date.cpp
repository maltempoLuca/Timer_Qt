//
// Created by Luca Maltempo on 05/11/21.
//

#include <QDate>
#include "../Headers/Date.h"

Date::Date() : daysOfWeek({"Monday", "Tuesday", "Wednesday",
                           "Thursday", "Friday", "Saturday", "Sunday"}) {
    QDate qDate = QDate::currentDate();
    day = qDate.day();
    dayOfWeek = qDate.dayOfWeek() - 1;
    month = qDate.month();
    year = qDate.year();
    isLeapYear = qDate.isLeapYear(year);
    dateFormat = DMY;
}

Date::Date(int day, int dayOfWeek, int month, int year, bool isLeapYear, DateFormat dateFormat) :
        daysOfWeek({"Monday", "Tuesday", "Wednesday",
                    "Thursday", "Friday", "Saturday", "Sunday"}),
        day(day),
        dayOfWeek(dayOfWeek),
        month(month),
        year(year),
        isLeapYear(isLeapYear),
        dateFormat(dateFormat) {}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    Date::day = day;

}

int Date::getDayOfWeek() const {
    return dayOfWeek;
}

void Date::setDayOfWeek(int dayOfWeek) {
    Date::dayOfWeek = dayOfWeek % 7;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    Date::month = month;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = year;
    verifyLeapYear(year);
}

void Date::verifyLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                setIsLeapYear(true);
            else
                setIsLeapYear(false);
        } else
            setIsLeapYear(true);
    } else
        setIsLeapYear(false);
}

void Date::setIsLeapYear(bool isLeapYear) {
    Date::isLeapYear = isLeapYear;
}

bool Date::getIsLeapYear() const {
    return isLeapYear;
}

const std::vector<std::string> &Date::getDaysOfWeek() const {
    return daysOfWeek;
}


Date::~Date() = default;
