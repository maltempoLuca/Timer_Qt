//
// Created by Luca Maltempo on 13/11/21.
//

#ifndef TIMER_QT_TIMER_H
#define TIMER_QT_TIMER_H

#include <QMainWindow>
#include "Observer.h"
#include "Clock.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Timer; }
QT_END_NAMESPACE

class Timer : public QMainWindow, public Observer {
Q_OBJECT

public:
    Timer(QWidget *parent = nullptr);

    ~Timer() override;

    void update() override;

private slots:

    void on_startButton_clicked();

    void on_hourTimerInput_returnPressed();

    void on_minuteTimerInput_returnPressed();

    void on_secondTimerInput_returnPressed();

    void on_hourTimerInput_selectionChanged();

    void on_minuteTimerInput_selectionChanged();

    void on_secondTimerInput_selectionChanged();

    void on_stopButton_clicked();

    void on_resetButton_clicked();

private:
    void initializeTimer();

    void initializeFormatMenu();

    void startTimer(const QString &hours, const QString &minutes, const QString &seconds);

    void dontStartTimer();


private:
    Ui::Timer *ui;
    Clock *clock;
    bool isTimerSet;
    bool isTimerActive;
    DateFormat dateFormat;
    TimeFormat timeFormat;
};


#endif //TIMER_QT_TIMER_H
