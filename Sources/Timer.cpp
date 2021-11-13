//
// Created by Luca Maltempo on 13/11/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Timer.h" resolved

#include <QMessageBox>
#include "../Headers/Timer.h"
#include "../Formats/ui_Timer.h"

Timer::Timer(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::Timer), clock(new Clock), isTimerSet(false), isTimerActive(false),
          dateFormat(DMY), timeFormat(Format24h) {
    ui->setupUi(this);
    clock->registerObserver(this);

    initializeFormatMenu();
    initializeTimer();
}

Timer::~Timer() {
    delete ui;
    delete clock;
}

void Timer::initializeFormatMenu() {
    ui->dateFormat->addItem(QString("DMY"));
    ui->dateFormat->addItem(QString("MDY"));
    ui->dateFormat->addItem(QString("YMD"));

    ui->timeFormat->addItem(QString("24h format"));
    ui->timeFormat->addItem(QString("12h format"));
}

void Timer::initializeTimer() {
    ui->hourTimerInput->setText("00");
    ui->hourTimerInput->setEnabled(true);
    ui->minuteTimerInput->setText("00");
    ui->minuteTimerInput->setEnabled(true);
    ui->secondTimerInput->setText("00");
    ui->secondTimerInput->setEnabled(true);

    ui->hoursTimer->display(00);
    ui->minutesTimer->display(00);
    ui->secondsTimer->display(00);
}

void Timer::on_hourTimerInput_returnPressed() {
    if (ui->hourTimerInput->text().toInt() < 0 || ui->hourTimerInput->text().toInt() > 99) {
        QMessageBox::StandardButton error = QMessageBox::warning(this, "Invalid input",
                                                                 "Insert a valid numbers of hours, 0 <= hours <= 99");
        ui->hourTimerInput->setText("00");
    } else {
        ui->hourTimerInput->setEnabled(false);

    }
}

void Timer::on_minuteTimerInput_returnPressed() {
    if (ui->minuteTimerInput->text().toInt() < 0 || ui->minuteTimerInput->text().toInt() > 59) {
        QMessageBox::StandardButton error = QMessageBox::warning(this, "Invalid input",
                                                                 "Insert a valid numbers of minutes, 0 <= minutes <= 59");
        ui->minuteTimerInput->setText("00");
    } else {
        ui->minuteTimerInput->setEnabled(false);
    }
}

void Timer::on_secondTimerInput_returnPressed() {
    if (ui->secondTimerInput->text().toInt() < 0 || ui->secondTimerInput->text().toInt() > 59) {
        QMessageBox::StandardButton error = QMessageBox::warning(this, "Invalid input",
                                                                 "Insert a valid numbers of seconds, 0 <= seconds <= 59");
        ui->secondTimerInput->setText("00");
    } else {
        ui->secondTimerInput->setEnabled(false);
    }
}

void Timer::on_hourTimerInput_selectionChanged() {
    ui->hourTimerInput->setText("");
}

void Timer::on_minuteTimerInput_selectionChanged() {
    ui->minuteTimerInput->setText("");
}

void Timer::on_secondTimerInput_selectionChanged() {
    ui->secondTimerInput->setText("");
}

void Timer::on_startButton_clicked() {
    if (!isTimerSet) {
        QString hours = ui->hourTimerInput->text();
        QString minutes = ui->minuteTimerInput->text();
        QString seconds = ui->secondTimerInput->text();
        if (!(hours == "" && minutes == "" && seconds == "")) {
            if (seconds.toInt() > 0) {
                startTimer(hours, minutes, seconds);
            } else {
                if (hours.toInt() > 0 || minutes.toInt() > 0) {
                    startTimer(hours, minutes, seconds);
                } else {
                    dontStartTimer();
                }
            }
        } else {
            dontStartTimer();
        }
    } else {
        isTimerActive = true;
    }
}

void Timer::startTimer(const QString &hours, const QString &minutes, const QString &seconds) {
    ui->hoursTimer->display(hours.toInt());
    ui->minutesTimer->display(minutes.toInt());
    ui->secondsTimer->display(seconds.toInt());
    isTimerSet = true;
    isTimerActive = true;
}

void Timer::dontStartTimer() {
    on_resetButton_clicked();
    QMessageBox::StandardButton error = QMessageBox::warning(this, "Ivalid Time",
                                                             "Please set a valid input for the timer.");
}

void Timer::on_stopButton_clicked() {
    isTimerActive = false;
}

void Timer::on_resetButton_clicked() {
    if (!isTimerActive) {
        isTimerActive = false;
        isTimerSet = false;
        initializeTimer();
    }
}


void Timer::update() {
    std::string currentDate = clock->getDate();
    // data
    ui->day->setText(QString::fromStdString(currentDate.substr(0, 2)));
    ui->month->setText(QString::fromStdString(currentDate.substr(3, 2)));
    ui->year->setText(QString::fromStdString(currentDate.substr(6)));
    ui->dayOfWeek->setText(QString::fromStdString(clock->getDayOfWeek()));

    std::string currentTime = clock->getTime();
    // orologio
    ui->clockTimeLabel->display(QString::fromStdString(currentTime));

    //timer
    if (isTimerActive) {
        ui->secondsTimer->display(ui->secondsTimer->value() - 1);
    }

}

