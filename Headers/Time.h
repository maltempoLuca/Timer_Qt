//
// Created by Luca Maltempo on 05/11/21.
//

#ifndef TIMER_QT_TIME_H
#define TIMER_QT_TIME_H

enum TimeFormat {
    Format12h, Format24h
};

class Time {
public:
    Time();

    Time(int seconds, int minutes, int hours, TimeFormat = Format24h);

public:

    int getSeconds() const;

    void setSeconds(int seconds);

    int getMinutes() const;

    void setMinutes(int minutes);

    int getHours() const;

    void setHours(int hours);

private:
    int seconds, minutes, hours;
    TimeFormat timeFormat;

};


#endif //TIMER_QT_TIME_H
