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

    void printFullDate(const DateFormat &dateFormat);

    void printFullTime(const TimeFormat &timeFormat);

    void setTime(int hours, int minutes, int second);

    void setDate(int day, int month, int year);

    void removeObserver(Observer *obs) override;

    void registerObserver(Observer *obs) override;

    void notify() const override;

    std::string getDayOfWeek();

    std::string getDate(const DateFormat &dateFormat);

    std::string getTime(const TimeFormat &timeFormat);


private slots:

    void increaseOneSecond();

private:
    void increaseOneDay();

    Date date;
    Time time;
    QTimer *qTimer;
    static const int OneSecondInMilliSecond;
    std::list<Observer *> observerList;
};


#endif //TIMER_QT_CLOCK_H
