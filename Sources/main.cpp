#include <QApplication>
#include <QPushButton>
#include "../Headers/Timer.h"
#include <iostream>

using namespace std;


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Clock clock;
    Timer t(nullptr, &clock);
    t.show();
    return a.exec();
}

