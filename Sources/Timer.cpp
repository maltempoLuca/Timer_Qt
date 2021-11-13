//
// Created by Luca Maltempo on 13/11/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Timer.h" resolved

#include <QMessageBox>
#include "../Headers/Timer.h"
#include "../Formats/ui_Timer.h"

Timer::Timer(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::Timer) {
    ui->setupUi(this);
    isTimerSet = false;
    isTimerActive = false;
    clock = new Clock;
    clock->registerObserver(this);
    // formati:
    ui->dateFormat->addItem(QString("DMY"));
    ui->dateFormat->addItem(QString("MDY"));
    ui->dateFormat->addItem(QString("YMD"));

    ui->timeFormat->addItem(QString("24h format"));
    ui->timeFormat->addItem(QString("12h format"));
}

Timer::~Timer() {
    delete ui;
    delete clock;
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

void Timer::on_startButton_clicked() {
    if (!isTimerSet) {
        if (!isTimerActive) {
            int hours = ui->hourTimerInput->text().toInt();
            int minutes = ui->minuteTimerInput->text().toInt();
            int seconds = ui->secondTimerInput->text().toInt();
            if (seconds > 0) {
                ui->hoursTimer->display(hours);
                ui->minutesTimer->display(minutes);
                ui->secondsTimer->display(seconds);
                isTimerSet = true;
                isTimerActive = true;
            } else {
                if (hours > 0 || minutes > 0) {
                    on_resetButton_clicked();
                    QMessageBox::StandardButton error = QMessageBox::warning(this, "Ivalid Time",
                                                                             "Please set a valid input for the timer.");
                }
            }
        }
    } else {
        isTimerActive = true;
    }

}

void Timer::on_stopButton_clicked() {
    isTimerActive = false;
}


void Timer::on_resetButton_clicked() {
    if (isTimerSet) {
        if (!isTimerActive) {
            isTimerActive = false;
            isTimerSet = false;
            ui->hourTimerInput->setText("00");
            ui->hourTimerInput->setEnabled(true);
            ui->minuteTimerInput->setText("00");
            ui->secondTimerInput->setEnabled(true);
            ui->secondTimerInput->setText("00");
            ui->secondTimerInput->setEnabled(true);

            ui->hoursTimer->display(00);
            ui->minutesTimer->display(00);
            ui->secondsTimer->display(00);
        }
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
