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
    // formati:
    ui->dateFormat->addItem(QString("DMY"));
    ui->dateFormat->addItem(QString("MDY"));
    ui->dateFormat->addItem(QString("YMD"));

    ui->timeFormat->addItem(QString("24h format"));
    ui->timeFormat->addItem(QString("12h format"));


    // data
    QString dayOfWeek = QString("Lunedi");
    ui->dayOfWeek->setText(dayOfWeek);
    QString day = QString("  24 ");
    ui->day->setText(day);
    QString month = QString("  04 ");
    ui->month->setText(month);
    QString year = QString(" 1998");
    ui->year->setText(year);

    // orologio:
    QString hours = QString(" 99 :");
    ui->hours->display(hours);
    QString minutes = QString(" 59 :");
    ui->minutes->display(minutes);
    QString seconds = QString(" 59  ");
    ui->seconds->display(seconds);
}

Timer::~Timer() {
    delete ui;
}

void Timer::on_pushButton_clicked() {
    QMessageBox::StandardButton error = QMessageBox::warning(this, "pippo", "pippo ha cliccato");

}


void Timer::on_hourTimerInput_returnPressed() {
    if (ui->hourTimerInput->text().toInt() < 0 || ui->hourTimerInput->text().toInt() > 99) {
        QMessageBox::StandardButton error = QMessageBox::warning(this, "Invalid input",
                                                                 "Insert a valid numbers of hours, 0 <= hours <= 99");
        ui->hourTimerInput->setText("00");
    } else {
        //salva valore per startTimer
        ui->hourTimerInput->setEnabled(false);

    }
}


void Timer::on_minuteTimerInput_returnPressed() {
    if (ui->minuteTimerInput->text().toInt() < 0 || ui->minuteTimerInput->text().toInt() > 59) {
        QMessageBox::StandardButton error = QMessageBox::warning(this, "Invalid input",
                                                                 "Insert a valid numbers of minutes, 0 <= minutes <= 59");
        ui->minuteTimerInput->setText("00");
    } else {
        //salva valore per startTimer
        ui->minuteTimerInput->setEnabled(false);


    }
}


void Timer::on_secondTimerInput_returnPressed() {
    if (ui->secondTimerInput->text().toInt() < 0 || ui->secondTimerInput->text().toInt() > 59) {
        QMessageBox::StandardButton error = QMessageBox::warning(this, "Invalid input",
                                                                 "Insert a valid numbers of seconds, 0 <= seconds <= 59");
        ui->secondTimerInput->setText("00");
    } else {
        //salva valore per startTimer
        ui->secondTimerInput->setEnabled(false);
    }
}


void Timer::on_hourTimerInput_selectionChanged() {
    ui->hourTimerInput->setText("");
}


void Timer::on_pushButton_2_clicked() {

}


void Timer::on_pushButton_3_clicked() {
    ui->hourTimerInput->setText("00");
    ui->hourTimerInput->setEnabled(true);
    ui->minuteTimerInput->setText("00");
    ui->secondTimerInput->setEnabled(true);
    ui->secondTimerInput->setText("00");
    ui->secondTimerInput->setEnabled(true);

}



