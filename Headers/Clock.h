//
// Created by Luca Maltempo on 05/11/21.
//

#ifndef TIMER_QT_CLOCK_H
#define TIMER_QT_CLOCK_H

#include "Date.h"
#include "Time.h"
#include <QTimer>
#include <QDate>

class Clock {
public:
    Clock();

    void getDATE();

    void getTIME();

private:
    QTimer qTimer;
    QTime qTime = QTime::currentTime();
    QDate qDate = QDate::currentDate();
    Date date = Date(qDate.day(), qDate.dayOfWeek(), qDate.month(), qDate.year(), qDate.isLeapYear(qDate.year()), DMY);
    Time time = Time(qTime.msec(), qTime.second(), qTime.minute(), qTime.hour(), Format12h);

};


#endif //TIMER_QT_CLOCK_H
