//
// Created by Luca Maltempo on 05/11/21.
//

#include <QTime>
#include "../Headers/Time.h"

Time::Time() : seconds(0), minutes(0), hours(0), timeFormat(Format24h) {
    initializeTime();
}

void Time::initializeTime() {
    QTime qTime = QTime::currentTime();
    setHours(qTime.hour());
    setMinutes(qTime.minute());
    setSeconds(qTime.second());
}

int Time::getSeconds() const {
    return seconds;
}

void Time::setSeconds(int seconds) {
    if (seconds >= 0 && seconds < 60) {
        Time::seconds = seconds;
    }
}

int Time::getMinutes() const {
    return minutes;
}

void Time::setMinutes(int minutes) {
    if (minutes >= 0 && minutes < 60) {
        Time::minutes = minutes;
    }
}

int Time::getHours() const {
    return hours;
}

void Time::setHours(int hours) {
    if (hours >= 0 && hours < 24) {
        Time::hours = hours;
    }
}



