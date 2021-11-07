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
    timeFormat = Format12h;
}

Time::Time(int seconds, int minutes, int hours, TimeFormat timeFormat) : seconds(seconds),
                                                                         minutes(minutes),
                                                                         hours(hours),
                                                                         timeFormat(timeFormat) {}

int Time::getSeconds() const {
    return seconds;
}

void Time::setSeconds(int secondsParameter) {
    Time::seconds = secondsParameter;
}

int Time::getMinutes() const {
    return minutes;
}

void Time::setMinutes(int minutesParameter) {
    Time::minutes = minutesParameter;
}

int Time::getHours() const {
    return hours;
}

void Time::setHours(int hoursParameter) {
    Time::hours = hoursParameter;
}



