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

void Clock::printFullDate(const DateFormat &dateFormat) {
    std::cout << date->getDayOfWeekAsString() << ", " << date->getFullDate(dateFormat) << std::endl;
}

void Clock::printFullTime(const TimeFormat &timeformat) {
    std::cout << time->getFullTime(timeformat) << std::endl;

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
        notify();
//        printFullTime();
//        printFullDate();
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

void Clock::setTime(int hours, int minutes, int second) {
    time->setFullTime(hours, minutes, second);
}

void Clock::setDate(int day, int month, int year) {
    date->setFullDate(day, month, year);
}

std::string Clock::getDate(const DateFormat &dateFormat) {
    std::string currentDate = date->getFullDate(dateFormat);
    return currentDate;
}

std::string Clock::getTime(const TimeFormat &timeFormat) {
    std::string currentTime = time->getFullTime(timeFormat);
    return currentTime;
}

void Clock::registerObserver(Observer *obs) {
    observerList.push_back(obs);
}

void Clock::removeObserver(Observer *obs) {
    observerList.remove(obs);
}

void Clock::notify() const {
    for (Observer *obs: observerList) {
        obs->update();
    }
}

std::string Clock::getDayOfWeek() {
    return date->getDayOfWeekAsString();
}


