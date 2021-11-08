//
// Created by Luca Maltempo on 05/11/21.
//

#include <QDate>
#include "../Headers/Date.h"

Date::Date() : day(0), dayOfWeek(0), month(0), year(0), isLeapYear(false), lastDayOfMonth(false), dateFormat(DMY),
               daysOfWeek({"Monday", "Tuesday", "Wednesday",
                           "Thursday", "Friday", "Saturday", "Sunday"}) {
    initializeDate();
}

void Date::initializeDate() {
    QDate qDate = QDate::currentDate();
    setDay(qDate.day());
    setDayOfWeek(qDate.dayOfWeek() - 1);
    setMonth(qDate.month());
    setYear(qDate.year());
}

Date::~Date() = default;


int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    if (isValidDay(day)) {
        Date::day = day;
    }
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
    if (month > 0 && month < 13) {
        Date::month = month;
    }
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    if (year >= 0) {
        Date::year = year;
        verifyLeapYear(year);
    }
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

bool Date::isValidDay(int newDay) {
    if (newDay > 0) {
        lastDayOfMonth = false;
        if (((month <= 7) && (month % 2 == 1)) || ((month > 7) && month % 2 == 0)) {
            if (newDay == 31) lastDayOfMonth = true;
            return (newDay < 32);
        } else {
            if (month != 2) {
                if (newDay == 30) lastDayOfMonth = true;
                return (newDay < 31);
            } else {
                if (isLeapYear) {
                    if (newDay == 29) lastDayOfMonth = true;
                    return (newDay < 30);
                } else {
                    if (newDay == 28) lastDayOfMonth = true;
                    return (newDay < 29);
                }
            }
        }
    } else {
        return false;
    }
}

bool Date::isLastDayOfMonth() const {
    return lastDayOfMonth;
}



