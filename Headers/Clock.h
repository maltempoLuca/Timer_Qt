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


class Clock : public QObject {
Q_OBJECT
public:
    Clock();

    void getDATE();

    virtual ~Clock();

    void getTIME();

public slots:

    void increase();

private:
    Date date;
    Time time;
    QTimer *qTimer;
};


#endif //TIMER_QT_CLOCK_H
