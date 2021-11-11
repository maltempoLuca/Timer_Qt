//
// Created by Luca Maltempo on 05/11/21.
//

#ifndef TIMER_QT_TIME_H
#define TIMER_QT_TIME_H

#include <iostream>
#include <iomanip>

enum TimeFormat {
    Format12h, Format24h
};

class Time {
public:
    Time();

    Time(int hours, int minutes, int seconds);

    void initializeTime();

public:

    void setSeconds(int newSeconds);

    void setMinutes(int newMinutes);

    void setHours(int newHours);

    void setFullTime(int newHours, int newMinutes, int newSeconds);

    int getSeconds() const;

    int getMinutes() const;

    int getHours() const;

    std::string getFullTime();


private:

    std::string formattedIntToString(int data);

    int seconds, minutes, hours;
    std::string pippo;
    TimeFormat timeFormat;
};


#endif //TIMER_QT_TIME_H
