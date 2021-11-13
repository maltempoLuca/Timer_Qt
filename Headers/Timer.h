//
// Created by Luca Maltempo on 13/11/21.
//

#ifndef TIMER_QT_TIMER_H
#define TIMER_QT_TIMER_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class Timer; }
QT_END_NAMESPACE

class Timer : public QMainWindow {
Q_OBJECT

public:
    Timer(QWidget *parent = nullptr);

    ~Timer();


private slots:

    void on_pushButton_clicked();

    void on_hourTimerInput_returnPressed();

    void on_minuteTimerInput_returnPressed();

    void on_secondTimerInput_returnPressed();

    void on_hourTimerInput_selectionChanged();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Timer *ui;
};


#endif //TIMER_QT_TIMER_H
