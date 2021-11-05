//
// Created by Luca Maltempo on 05/11/21.
//

#include "Date.h"

Date::Date(int day, int dayOfWeek, int month, int year, bool isLeapYear, DateFormat dateFormat) : day(day),
                                                                                                  dayOfWeek(dayOfWeek),
                                                                                                  month(month),
                                                                                                  year(year),
                                                                                                  isLeapYear(
                                                                                                          isLeapYear),
                                                                                                  dateFormat(
                                                                                                          dateFormat) {}

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
    Date::dayOfWeek = dayOfWeek;
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
}

bool Date::isLeapYear1() const {
    return isLeapYear;
}

void Date::setIsLeapYear(bool isLeapYear) {
    Date::isLeapYear = isLeapYear;
}


Date::~Date() = default;
