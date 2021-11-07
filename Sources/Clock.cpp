//
// Created by Luca Maltempo on 05/11/21.
//

#include "../Headers/Clock.h"

Clock::Clock() : date(), time() {
    qTimer = new QTimer(this);
    connect(qTimer, SIGNAL(timeout()), this, SLOT(increaseOneSecond()));
    qTimer->start(1000);
}

Clock::~Clock() {
    // qTimer's parent is clock, a QObject, you don't have to manually delete qTimer. Read QT Memory Management.
}


void Clock::printFullDate() {
    std::cout << "Date: " << date.getDaysOfWeek()[date.getDayOfWeek()] << " " << date.getDay() << "/" << date.getMonth()
              << "/" << date.getYear() << std::endl;
}

void Clock::printFullTime() {
    std::cout << "Time: " << std::setfill('0') << std::setw(2) << time.getHours() << ":" << std::setfill('0')
              << std::setw(2) << time.getMinutes() << ":" << std::setfill('0') << std::setw(2) << time.getSeconds()
              << std::endl;
}

void Clock::increaseOneSecond() {
    if (time.getSeconds() < 59) {
        time.setSeconds(time.getSeconds() + 1);
    } else {
        time.setSeconds(0);
        if (time.getMinutes() < 59) {
            time.setMinutes(time.getMinutes() + 1);
        } else {
            time.setMinutes(0);
            if (time.getHours() < 23) {
                time.setHours(time.getHours() + 1);
            } else {
                time.setHours(0);
                setNextDay();
            }
        }
    }
    printFullTime();
    printFullDate();
}

void Clock::setNextDay() {
    if (date.isNotLastDayOfMonth()) {
        date.setDay(date.getDay() + 1);
        date.setDayOfWeek(date.getDayOfWeek() + 1);
    } else {
        date.setDay(1);
        date.setDayOfWeek(date.getDayOfWeek() + 1);
        if (date.getMonth() < 12) {
            date.setMonth(date.getMonth() + 1);
        } else {
            date.setMonth(1);
            date.setYear(date.getYear() + 1);
        }
    }
}

