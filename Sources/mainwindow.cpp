//
// Created by Luca Maltempo on 05/11/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainWindow.h" resolved

#include "../Headers/mainwindow.h"
#include "../Formats/ui_mainwindow.h"
#include <QDebug>
#include <QDateTime>


mainWindow::mainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::mainWindow) {
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunction()));
    //timer->start(1000);
}

mainWindow::~mainWindow() {
    delete ui;
}

void mainWindow::myfunction() {
    QTime time = QTime::currentTime();
    QString timeText = time.toString("hh : mm : ss : zzz");
    ui->label_dat_time->setText(timeText);
}

