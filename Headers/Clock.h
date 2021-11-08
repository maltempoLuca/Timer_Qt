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
    const std::unique_ptr<Date> date;
    const std::unique_ptr<Time> time;
    QTimer *qTimer;
    static const int OneSecondInMilliSecond;

    void increaseOneDay();


};


#endif //TIMER_QT_CLOCK_H
