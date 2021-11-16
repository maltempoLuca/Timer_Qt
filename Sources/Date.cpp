//
// Created by Luca Maltempo on 05/11/21.
//

#include <QDate>
#include "../Headers/Date.h"

Date::Date() : day(1), dayOfWeek(4), month(1), year(1970), leapYear(false), lastDayOfMonth(false),
               daysOfWeek({"Sunday", "Monday", "Tuesday", "Wednesday",
                           "Thursday", "Friday", "Saturday"}) {
    initializeDate();
}

Date::Date(int day, int month, int year) : Date() {
    setFullDate(day, month, year);
}

Date::~Date() = default;

void Date::initializeDate() {
    QDate qDate = QDate::currentDate();
    setDay(qDate.day());
    setMonth(qDate.month());
    setYear(qDate.year());
}

void Date::setDay(int newDay) {
    if (isValidDay(newDay)) {
        Date::day = newDay;
        setDayOfWeekFromCurrentDate();
    } else {
        throw std::invalid_argument("Invalid newDay");
    }
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
                if (leapYear) {
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

void Date::setDayOfWeekFromCurrentDate() {
    int localMonth = month;
    int localYear = year;
    int localDay = day;
    static const int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    localYear -= localMonth < 3;
    dayOfWeek = (localYear + localYear / 4 - localYear / 100 + localYear / 400 + t[localMonth - 1] + localDay) % 7;
}

void Date::setMonth(int newMonth) {
    if (isValidMonth(newMonth)) {
        Date::month = newMonth;
        setDayOfWeekFromCurrentDate();
    } else {
        throw std::invalid_argument("Invalid newMonth");
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

void Date::setYear(int newYear) {
    if (isValidYear(newYear)) {
        Date::year = newYear;
        verifyLeapYear(newYear);
        setDayOfWeekFromCurrentDate();
    } else {
        throw std::invalid_argument("Invalid newYear");
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

void Date::verifyLeapYear(int newYear) {
    if (newYear % 4 == 0) {
        if (newYear % 100 == 0) {
            if (newYear % 400 == 0)
                leapYear = true;
            else
                leapYear = false;
        } else
            leapYear = true;
    } else
        leapYear = false;
}

void Date::setFullDate(int newDay, int newMonth, int newYear) {
        setYear(newYear);
        Date::month = 1;
        Date::day = 1;
        setMonth(newMonth);
        setDay(newDay);
}

std::string Date::getFullDate(const DateFormat &dateFormat) const {
    std::string fullDate;
    std::string currentDay = std::string(2 - std::to_string(day).length(), '0') + std::to_string(day);
    std::string currentMonth = std::string(2 - std::to_string(month).length(), '0') + std::to_string(month);
    std::string currentYear = std::to_string(year);
    switch (dateFormat) {
        case DMY :
            fullDate = currentDay + "/" + currentMonth + "/" + currentYear;
            break;
        case MDY :
            fullDate = currentMonth + "/" + currentDay + "/" + currentYear;
            break;
        case YMD:
            fullDate = currentYear + "/" + currentMonth + "/" + currentDay;
            break;
        case ReducedFormat:
            fullDate = currentDay + "/" + currentMonth;
            break;
    }
    return fullDate;
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}


int Date::getYear() const {
    return year;
}

bool Date::isLeapYear() const {
    return leapYear;
}

bool Date::isLastDayOfMonth() const {
    return lastDayOfMonth;
}

const std::string &Date::getDayOfWeekAsString() const {
    return daysOfWeek[dayOfWeek];
}




