#include <QCoreApplication>
#include <QtCore/qtimer.h>
#include "gtest/gtest.h"


int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);

    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    QTimer exitTimer;
    QObject::connect(&exitTimer, &QTimer::timeout, &app, QCoreApplication::quit);
    exitTimer.start();
    app.exec();
    return ret;
}