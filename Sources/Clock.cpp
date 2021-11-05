//
// Created by Luca Maltempo on 05/11/21.
//

#include "../Headers/Clock.h"
#include <iostream>


Clock::Clock() {}

void Clock::getDATE() {
    std::cout << "Date: " << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << "/"
              << date.getDayOfWeek() << "\n";
}

void Clock::getTIME() {
    std::cout << "Time: " << time.getHours() << ":" << time.getMinutes() << ":" << time.getSeconds() << "\n";
}