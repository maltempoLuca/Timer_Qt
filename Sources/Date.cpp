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

Date::Date(int day, int month, int year) : Date() {
    setFullDate(day, month, year);
}

void Date::initializeDate() {
    QDate qDate = QDate::currentDate();
    setDay(qDate.day());
    setDayOfWeek(qDate.dayOfWeek() - 1);
    setMonth(qDate.month());
    setYear(qDate.year());
}

Date::~Date() = default;

void Date::setFullDate(int day, int month, int year) {
    int currentDay = Date::day;
    int currentMonth = Date::month;
    int currentYear = Date::year;
    try {
        setYear(year);
        Date::day = 1;
        Date::month = 1;
        setMonth(month);
        setDay(day);
    } catch (const std::invalid_argument &e) {
        std::cout << e.what();
        Date::day = currentDay;
        Date::month = currentMonth;
        Date::year = currentYear;
    }
}

void Date::setDateFormat(DateFormat dateFormat) {
    Date::dateFormat = dateFormat;
}

std::string Date::getFullDate() {
    switch (dateFormat) {
        case DMY :
            return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
            break;
        case MDY :
            return std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year);
            break;
        case YMD:
            return std::to_string(year) + "/" + std::to_string(month) + "/" + std::to_string(day);
            break;
        case ReducedFormat:
            return std::to_string(day) + "/" + std::to_string(month);
            break;
    }
}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    if (isValidDay(day)) {
        Date::day = day;
    } else {
        throw std::invalid_argument("Invalid day");
    }
}

int Date::getDayOfWeek() const {
    return dayOfWeek;
}

void Date::setDayOfWeek(int dayOfWeek) {
    if (dayOfWeek > -1) {
        Date::dayOfWeek = dayOfWeek % 7;
    } else {
        throw std::invalid_argument("Invalid dayOfWeek");
    }
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    if (isValidMonth(month)) {
        Date::month = month;
    } else {
        throw std::invalid_argument("Invalid month");
    }
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    if (isValidYear(year)) {
        Date::year = year;
        verifyLeapYear(year);
    } else {
        throw std::invalid_argument("Invalid year");
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

bool Date::isLastDayOfMonth() const {
    return lastDayOfMonth;
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

bool Date::isValidMonth(int newMonth) {
    int currentMonth = month;
    if (newMonth > 0 && newMonth < 13) {
        month = newMonth;
        if (isValidDay(day)) {
            month = currentMonth;
            return true;
        } else {
            month = currentMonth;
            return false;
        }
    } else {
        return false;
    }
}

bool Date::isValidYear(int newYear) {
    int currentYear = year;
    if (newYear >= 0) {
        year = newYear;
        if (isValidDay(day)) {
            year = currentYear;
            return true;
        } else {
            year = currentYear;
            return false;
        }
    } else {
        return false;
    }
}






