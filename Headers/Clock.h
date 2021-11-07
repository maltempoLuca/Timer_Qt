//
// Created by Luca Maltempo on 05/11/21.
//

#ifndef TIMER_QT_CLOCK_H
#define TIMER_QT_CLOCK_H

#include "Date.h"
#include "Time.h"
#include <QObject>
#include <QTimer>
#include <QDate>
#include <iostream>
#include <iomanip>

class Clock : public QObject {
Q_OBJECT
public:
    Clock();

    void printFullDate();

    virtual ~Clock();

    void printFullTime();

private slots:

    void increaseOneSecond();

private:
    Date date;
    Time time;
    QTimer *qTimer;

    void setNextDay();

    bool isNotLastDayOfMonth();
};


#endif //TIMER_QT_CLOCK_H
