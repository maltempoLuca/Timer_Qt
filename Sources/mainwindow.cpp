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
    clock = new Clock;
    clock->registerObserver(this);
}

mainWindow::~mainWindow() {
    delete ui;
    delete clock;
}

void mainWindow::update() {
    std::string currentDate = clock->getDate();
    std::string currentTime = clock->getTime();
    ui->label_dat_time->setText(QString::fromStdString(currentTime));
}

