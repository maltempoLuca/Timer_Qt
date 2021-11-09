//
// Created by Luca Maltempo on 05/11/21.
//

#include <QDate>
#include "../Headers/Date.h"

Date::Date() : day(1), dayOfWeek(4), month(1), year(1970), leapYear(false), lastDayOfMonth(false), dateFormat(DMY),
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

//TODO: capisci come gestire queste eccezioni lanciate.
void Date::setDay(int day) {
    if (isValidDay(day)) {
        Date::day = day;
        setDayOfWeekFromCurrentDate();
    } else {
        throw std::invalid_argument("Invalid day");
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

void Date::setMonth(int month) {
    if (isValidMonth(month)) {
        Date::month = month;
        setDayOfWeekFromCurrentDate();
    } else {
        throw std::invalid_argument("Invalid month");
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

void Date::setYear(int year) {
    if (isValidYear(year)) {
        Date::year = year;
        verifyLeapYear(year);
        setDayOfWeekFromCurrentDate();
    } else {
        throw std::invalid_argument("Invalid year");
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

void Date::setFullDate(int newDay, int newMonth, int newYear) {
    int currentDay = Date::day;
    int currentMonth = Date::month;
    int currentYear = Date::year;
    int currentDayOfWeek = Date::dayOfWeek;
    bool currentYearIsLeap = Date::leapYear;
    bool currentDayIsLastOfMonth = Date::lastDayOfMonth;

    try {
        setYear(newYear);
        Date::month = 1;
        Date::day = 1;
        setMonth(newMonth);
        setDay(newDay);
    } catch (const std::invalid_argument &e) {
        std::cout << e.what();
        Date::day = currentDay;
        Date::month = currentMonth;
        Date::year = currentYear;
        Date::dayOfWeek = currentDayOfWeek;
        Date::leapYear = currentYearIsLeap;
        Date::lastDayOfMonth = currentDayIsLastOfMonth;
    }
}

void Date::setDateFormat(DateFormat dateFormat) {
    Date::dateFormat = dateFormat;
}

//TODO: capisci come ritornare stringhe.
std::string Date::getFullDate() const {
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


int Date::getDayOfWeek() const {
    return dayOfWeek;
}


int Date::getMonth() const {
    return month;
}


int Date::getYear() const {
    return year;
}


void Date::setIsLeapYear(bool isLeapYear) {
    Date::leapYear = isLeapYear;
}

bool Date::getIsLeapYear() const {
    return leapYear;
}

bool Date::isLastDayOfMonth() const {
    return lastDayOfMonth;
}

const std::string &Date::gatDayOfWeekAsString() const {
    return daysOfWeek[dayOfWeek];
}




