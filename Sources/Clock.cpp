//
// Created by Luca Maltempo on 05/11/21.
//

#include "../Headers/Clock.h"

Clock::Clock() : date(), time() {
    qTimer = new QTimer(this);
    connect(qTimer, SIGNAL(timeout()), this, SLOT(increase()));
    qTimer->start(10);
}

Clock::~Clock() {
    delete qTimer;
}


void Clock::getDATE() {
    std::cout << "Date: " << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << "/"
              << date.getDayOfWeek() << "\n";
}

void Clock::getTIME() {
    std::cout << "Time: " << time.getHours() << ":" << time.getMinutes() << ":" << time.getSeconds() << "\n";
}

void Clock::increase() {
    QTime time = QTime::currentTime();
    QString timeText = time.toString("hh : mm : ss : zzz");
    std::cout << timeText.toStdString() << "\n";
}

