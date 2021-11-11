//
// Created by Luca Maltempo on 11/11/21.
//

#ifndef TIMER_QT_OBSERVER_H
#define TIMER_QT_OBSERVER_H

class Observer {

protected:
    virtual ~Observer() = default;

public:
    virtual void update() = 0;

};

#endif //TIMER_QT_OBSERVER_H
