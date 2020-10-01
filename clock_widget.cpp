#include <clock_widget.h>

#include <QPainter>
#include <QTime>
#include <iostream>
#include <string>

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
    //std::cout << "Tick" << std::endl;
}
void drawKek(QPainter& p)
{
    p.drawText(0,0,QString("kek"));
}

void Clock::paintEvent(QPaintEvent*)
{
	QPainter p(this);
	QPoint center(width()/2, height()/2);
	p.translate(center);

	// seconds
	p.save();
    p.rotate((_seconds - 30) * 6);
    p.scale(5,12);
    p.setPen(Qt::red);
    p.drawLine(0,0,0,9);
	p.restore();
    // minutes
    p.save();
    p.rotate((_minutes - 30) * 6);
    p.scale(5,12);
    p.setPen(Qt::blue);
    p.drawLine(0,0,0,8);
    p.restore();
    //hours
    p.save();
    p.rotate(_hours * 6);
    p.scale(5,12);
    p.setPen(Qt::yellow);
    p.drawLine(0,0, 0,7);
    p.restore();

    //lines
    for (int i = 0; i < 360; i+=6)
    {
        p.save();
        p.rotate(i);
        if (i % 5 == 0)
        {
            p.scale(2,1);
            p.drawLine(0,-128,0, -105);
        }
        else
        {
            p.drawLine(0, -128, 0, -110);
        }
        p.restore();
    }

    //numbers
    p.drawText(45,  -75, "1");
    p.drawText(80,  -43, "2");
    p.drawText(93,  6,   "3");
    p.drawText(80,  55,  "4");
    p.drawText(45,  87,  "5");
    p.drawText(-4,  102, "6");
    p.drawText(-52, 89,  "7");
    p.drawText(-90, 55,  "8");
    p.drawText(-103,6,   "9");
    p.drawText(-90, -40, "10");
    p.drawText(-54, -75, "11");
    p.drawText(-8,  -85, "12");

    //circle
    p.drawEllipse(QRectF(-128,-128,256,256));

    //number clock
    p.scale(2,2);
    p.drawText(-32, 80,
               QString::number(_hours) +  ":" +
               QString::number(_minutes)+ ":" +
               QString::number(_seconds));
}


