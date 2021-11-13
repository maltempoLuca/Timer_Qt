//
// Created by Luca Maltempo on 05/11/21.
//

#ifndef TIMER_QT_MAINWINDOW_H
#define TIMER_QT_MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "Observer.h"
#include "Clock.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainWindow; }
QT_END_NAMESPACE

class mainWindow : public QMainWindow, public Observer {
Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = nullptr);

    ~mainWindow() override;

    void update() override;


private:
    Ui::mainWindow *ui;
    Clock *clock;
};

#endif // TIMER_QT_MAINWINDOW_H