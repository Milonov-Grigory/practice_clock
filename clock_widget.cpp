#include <clock_widget.h>

#include <QPainter>
#include <QTime>
#include <iostream>

static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += M_PI * 2 ;
    while (angle > M_PI * 2 )
        angle -= M_PI * 2 ;
    return angle;
}

Clock::Clock(QWidget* parent)
    : QWidget(parent)
    , _hours(0)
    , _minutes(0)
    , _seconds(0)
{
    setMinimumSize(100,100);
    startTimer(1000);
    _hoursArrow << QPoint(0,0) << QPoint(0,100) << QPoint(0,100)
                << QPoint(-15,70) << QPoint(0,100) << QPoint(15,70)
                << QPoint(0,100);

    _minutesArrow << QPoint(0,0) << QPoint(0,100) << QPoint(0,100)
                  << QPoint(-15,70) << QPoint(0,100) << QPoint(15,70)
                  << QPoint(0,100);


    _secondsArrow << QPoint(0,0) << QPoint(0,100) << QPoint(0,100)
                  << QPoint(-15,70) << QPoint(0,100) << QPoint(15,70)
                  << QPoint(0,100);


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



    _hoursArrowAngle = 1/3600;
    QMatrix hoursMatrix;
    hoursMatrix.rotate(_hoursArrowAngle);
    _hoursArrow = hoursMatrix.map(_hoursArrow);

    _minutesArrowAngle = 1/60;
    QMatrix minutesMatrix;
    minutesMatrix.rotate(_minutesArrowAngle);
    _minutesArrow = minutesMatrix.map(_minutesArrow);

    _secondsArrowAngle = 1/60;
    QMatrix secondsMatrix;
    secondsMatrix.rotate(_secondsArrowAngle);
    _secondsArrow = secondsMatrix.map(_secondsArrow);
}


void Clock::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    QPoint center(width()/2, height()/2);
    p.translate(center);

    p.save();
    p.rotate( 180 + _hours * 30);
    p.drawPolygon(_hoursArrow);
    p.restore();

    p.save();
    p.rotate( 180 + _minutes * 6);
    p.drawPolygon(_minutesArrow);
    p.restore();

    p.save();
    p.rotate( 180 + _seconds * 6);
    p.drawPolygon(_secondsArrow);
    p.restore();

    QFont fontTime = p.font();
    QFont fontDial = p.font();
    fontTime.setPointSize(15);

    p.setFont(fontTime);


    p.drawText(QPoint(-40,0), QString::number(_hours));
    p.drawText(QPoint(-4,0), QString(":"));
    p.drawText(QPoint(10,0), QString::number(_minutes));

    p.setFont(fontDial);

    qreal phi = 5*M_PI/3;
    int radius = 120;
    for (int i = 0; i < 12; ++i)
    {
            //if ((i+1)%3 == 0)
            p.drawText((int)radius*cos(phi)-10,(int)radius*sin(phi) - 10, 20, 20, Qt::AlignCenter, QString::number(i+1));
        phi += M_PI/6;
        phi = normalizeAngle(phi);
    }

    phi = 0;
    radius = 110;
    for (int i = 0; i < 12; ++i)
    {


        p.drawLine(radius*cos(phi)*0.9,radius*sin(phi)*0.9, radius*cos(phi),radius*sin(phi));
        phi += M_PI/6;
    }

    /* Не очень красиво получилось - требуется другое решение
    // hours
    p.save();
    p.rotate( 180 + _hours * 30);
    p.scale(7,7);
    p.setPen(Qt::red);
    drawArrow(p);
    p.restore();

  // minutes
    p.save();
    p.rotate( 180 + _minutes * 6);
    p.scale(18,18);
    p.setPen(Qt::green);
    drawArrow(p);
    p.restore();
*/
    // seconds
    //	p.save();
    //	p.rotate( 180 + _seconds * 6);
    //	p.scale(20,20);
    //	p.setPen(Qt::blue);
    //	drawArrow(p);
    //	p.restore();
}

