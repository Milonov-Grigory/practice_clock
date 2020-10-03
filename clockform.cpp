#include "clockform.h"
#include "ui_clockform.h"
#include <QTime>
ClockForm::ClockForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClockForm)
{
    ui->setupUi(this);
    startTimer(1000);
}

ClockForm::~ClockForm()
{
    delete ui;
}
void ClockForm::timerEvent(QTimerEvent *){
    QTime t  = QTime::currentTime();
    ui->clockWgt->_hours = t.hour();
    ui->clockWgt->_minutes = t.minute();
    ui->clockWgt->_seconds = t.second();
    ui->hoursLbl->setNum(ui->clockWgt->_hours);
    ui->minutesLbl->setNum(ui->clockWgt->_minutes);
    ui->secondsLbl->setNum(ui->clockWgt->_seconds);
    ui->clockWgt->update();
}
