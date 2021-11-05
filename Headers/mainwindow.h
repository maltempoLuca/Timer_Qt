//
// Created by Luca Maltempo on 05/11/21.
//

#ifndef TIMER_QT_MAINWINDOW_H
#define TIMER_QT_MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class mainWindow; }
QT_END_NAMESPACE

class mainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = nullptr);

    ~mainWindow() override;

public slots:

    void myfunction();

private:
    Ui::mainWindow *ui;
    QTimer *timer;
};

#endif // TIMER_QT_MAINWINDOW_H