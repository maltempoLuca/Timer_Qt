//
// Created by Luca Maltempo on 05/11/21.
//

#include <QTime>
#include "../Headers/Time.h"

Time::Time() {
    QTime qTime = QTime::currentTime();
    hours = qTime.hour();
    minutes = qTime.minute();
    seconds = qTime.second();
    milliSeconds = qTime.msec();
    timeFormat = Format12h;
}

Time::Time(int milliSeconds, int seconds, int minutes, int hours, TimeFormat timeFormat) : milliSeconds(milliSeconds),
                                                                                           seconds(seconds),
                                                                                           minutes(minutes),
                                                                                           hours(hours),
                                                                                           timeFormat(timeFormat) {}


int Time::getMilliSeconds() const {
    return milliSeconds;
}

void Time::setMilliSeconds(int milliSeconds) {
    Time::milliSeconds = milliSeconds;
}

int Time::getSeconds() const {
    return seconds;
}

void Time::setSeconds(int seconds) {
    Time::seconds = seconds;
}

int Time::getMinutes() const {
    return minutes;
}

void Time::setMinutes(int minutes) {
    Time::minutes = minutes;
}

int Time::getHours() const {
    return hours;
}

void Time::setHours(int hours) {
    Time::hours = hours;
}



