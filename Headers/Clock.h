//
// Created by Luca Maltempo on 05/11/21.
//

#ifndef TIMER_QT_CLOCK_H
#define TIMER_QT_CLOCK_H

#include "Date.h"
#include "Time.h"
#include "Subject.h"
#include "Observer.h"

#include <QObject>
#include <QTimer>
#include <QDate>
#include <iostream>
#include <iomanip>

class Clock : public QObject, public Subject {
Q_OBJECT
public:
    Clock();

    virtual ~Clock();

    void printFullDate();

    void printFullTime();

    void setDateFormat(const DateFormat &dateFormat);

    void setTimeFormat(const TimeFormat &timeFormat);

    void setTime(int hours, int minutes, int second);

    void setDate(int day, int month, int year);

    std::string getDate();

    std::string getTime();

    void notify() const override;

    void removeObserver(Observer *obs) override;

    void registerObserver(Observer *obs) override;

private slots:

    void increaseOneSecond();

private:
    void increaseOneDay();

    const std::unique_ptr<Date> date;
    const std::unique_ptr<Time> time;
    QTimer *qTimer;
    static const int OneSecondInMilliSecond;
    std::list<Observer *> observerList;

};


#endif //TIMER_QT_CLOCK_H
