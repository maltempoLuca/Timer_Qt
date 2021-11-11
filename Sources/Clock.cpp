//
// Created by Luca Maltempo on 05/11/21.
//

#include "../Headers/Clock.h"

const int Clock::OneSecondInMilliSecond = 1000;

Clock::Clock() : date(std::make_unique<Date>()), time(std::make_unique<Time>()) {
    qTimer = new QTimer(this);
    connect(qTimer, SIGNAL(timeout()), this, SLOT(increaseOneSecond()));
    qTimer->start(OneSecondInMilliSecond);
}

Clock::~Clock() {
    // qTimer's parent is clock, a QObject, you don't have to manually delete qTimer. Read QT Memory Management.
}

void Clock::printFullDate() {
    std::cout << date->getFullDate() << std::endl;
}

void Clock::printFullTime() {
    std::cout << time->getFullTime() << std::endl;

}

void Clock::increaseOneSecond() {
    try {
        if (time->getSeconds() < 59) {
            time->setSeconds(time->getSeconds() + 1);
        } else {
            time->setSeconds(0);
            if (time->getMinutes() < 59) {
                time->setMinutes(time->getMinutes() + 1);
            } else {
                time->setMinutes(0);
                if (time->getHours() < 23) {
                    time->setHours(time->getHours() + 1);
                } else {
                    time->setHours(0);
                    increaseOneDay();
                }
            }
        }
        printFullTime();
        printFullDate();
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        //TODO: chiamare una nuova inizializzazione dell'orologio?
    }
}

void Clock::increaseOneDay() {
    if (!date->isLastDayOfMonth()) {
        date->setDay(date->getDay() + 1);
    } else {
        date->setDay(1);
        if (date->getMonth() < 12) {
            date->setMonth(date->getMonth() + 1);
        } else {
            date->setMonth(1);
            date->setYear(date->getYear() + 1);
        }
    }
}

