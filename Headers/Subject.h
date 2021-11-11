//
// Created by Luca Maltempo on 11/11/21.
//

#ifndef TIMER_QT_SUBJECT_H
#define TIMER_QT_SUBJECT_H

#include "Observer.h";

class Subject {

protected:
    virtual ~Subject() = default;

public:
    virtual void registerObserver(Observer *obs) = 0;

    virtual void removeObserver(Observer *obs) = 0;

    virtual void notify() const = 0;
};

#endif //TIMER_QT_SUBJECT_H
