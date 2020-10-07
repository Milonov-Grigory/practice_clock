
#include <clockwidget.h>

#include <QPainter>
#include <QTime>
#include <iostream>

Clock::Clock(QWidget* parent)
    : QWidget(parent)
    , _hours(0)
    , _minutes(0)
    , _seconds(0)
{
    setMinimumSize(100,100);
    startTimer(1000);
}

void Clock::timerEvent(QTimerEvent*)
{
    QTime t  = QTime::currentTime();
    _hours   = t.hour();
    _minutes = t.minute();
    _seconds = t.second();

    update();
    std::cout << "Tick: "
    << _hours
    << ":" << _minutes
    << ":" << _seconds
    << std::endl;
}


void drawArrow(QPainter& p, double i, double j, Qt::GlobalColor color, int angle)
{

    p.save();
    p.rotate( 180 + angle);
    p.scale(i,j);
    p.setPen(color);
    p.drawLine(0,0, 0, 20);
    p.restore();

}

void Clock::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    QPoint center(width()/2, height()/2);
    p.translate(center);


    for (int i = 0; i<60; i++) {
        p.drawLine(145, 0, 150, 0);
        p.rotate(6);
    }

    for (int i = 0; i<12; i++) {
        p.drawLine(140,0,150,0);
        p.rotate(30);
    }

    drawArrow(p,8,4,Qt::white, _hours*30);
    drawArrow(p, 7, 6, Qt::white, _minutes*6);
    drawArrow(p,5, 6.5, Qt::red, _seconds*6);

    p.scale(2,2);
    p.drawText(-28, -90, QString::number(_hours) + ":" + QString::number(_minutes) + ":" + QString::number(_seconds));
}

