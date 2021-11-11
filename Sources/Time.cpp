//
// Created by Luca Maltempo on 05/11/21.
//

#include <QTime>
#include "../Headers/Time.h"

Time::Time() : seconds(0), minutes(0), hours(0), timeFormat(Format24h) {
    initializeTime();
}

Time::Time(int hours, int minutes, int seconds) : Time() {
    Time::setFullTime(hours, minutes, seconds);
}

void Time::initializeTime() {
    QTime qTime = QTime::currentTime();
    setHours(qTime.hour());
    setMinutes(qTime.minute());
    setSeconds(qTime.second());
}

void Time::setSeconds(int newSeconds) {
    if (newSeconds >= 0 && newSeconds < 60) {
        Time::seconds = newSeconds;
    } else {
        throw std::invalid_argument("Invalid newSeconds");
    };
}

void Time::setMinutes(int newMinutes) {
    if (newMinutes >= 0 && newMinutes < 60) {
        Time::minutes = newMinutes;
    } else {
        throw std::invalid_argument("Invalid newMinutes");
    }
}

void Time::setHours(int newHours) {
    if (newHours >= 0 && newHours < 24) {
        Time::hours = newHours;
    } else {
        throw std::invalid_argument("Invalid newHours");
    }
}

void Time::setFullTime(int newHours, int newMinutes, int newSeconds) {
    int currentSeconds = Time::seconds;
    int currentMinutes = Time::minutes;
    int currentHours = Time::hours;
    try {
        setSeconds(newSeconds);
        setMinutes(newMinutes);
        setHours(newHours);
    } catch (const std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        Time::seconds = currentSeconds;
        Time::minutes = currentMinutes;
        Time::hours = currentHours;
    }
}

void Time::setTimeFormat(TimeFormat timeFormat) {
    Time::timeFormat = timeFormat;
}

int Time::getSeconds() const {
    return seconds;
}

int Time::getMinutes() const {
    return minutes;
}

int Time::getHours() const {
    return hours;
}

std::string Time::getFullTime() {
    std::string formattedHours;
    std::string formattedMinutes = formattedIntToString(minutes);
    std::string formattedSeconds = formattedIntToString(seconds);
    switch (timeFormat) {
        case Format24h :
            formattedHours = formattedIntToString(hours);
            break;
        case Format12h :
            if (hours < 13) {
                formattedHours = formattedIntToString(hours);
                formattedSeconds = formattedSeconds + " AM";
            } else {
                formattedHours = formattedIntToString(hours - 12);
                formattedSeconds = formattedSeconds + " PM";
            }
            break;
    }
    std::string fullTime = formattedHours + ":" + formattedMinutes + ":" + formattedSeconds;
    return fullTime;
}


std::string Time::formattedIntToString(int data) {
    std::string dataToString = std::to_string(data);
    std::string dataFormatted = std::string(2 - dataToString.length(), '0') + dataToString;
    return dataFormatted;
}






