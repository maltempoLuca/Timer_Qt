#include <QApplication>
#include <QPushButton>
#include "../Headers/mainwindow.h"
#include "../Headers/Clock.h"
#include <iostream>
#include <chrono>

using namespace std;


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    mainWindow w;
    w.show();
    Clock clock;
    clock.getDATE();
    clock.getTIME();
    return a.exec();
}
