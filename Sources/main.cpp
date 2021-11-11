#include <QApplication>
#include <QPushButton>
#include "../Headers/mainwindow.h"
#include "../Headers/Clock.h"
#include <iostream>

using namespace std;


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
//    mainWindow w;
//    w.show();
    Clock clock;
    return a.exec();
}
