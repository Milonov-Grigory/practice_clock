#include <clock_widget.h>

#include <QPainter>
#include <QTime>
#include <QtMath>


Clock::Clock(QWidget* parent)
	: QWidget(parent)
	, _hours(0)
	, _minutes(0)
	, _seconds(0)
{
	setMinimumSize(100,100);
    //startTimer(1000);
}

//void Clock::timerEvent(QTimerEvent*)
//{
//	QTime t  = QTime::currentTime();
//	_hours   = t.hour();
//	_minutes = t.minute();
//	_seconds = t.second();
//	update();
//}


void drawArrow(QPainter& p)
{
	p.drawLine(0,0,  0,10);
	p.drawLine(0,10,-3, 7);
	p.drawLine(0,10, 3, 7);
}

void Clock::paintEvent(QPaintEvent*)
{
	QPainter p(this);
	QPoint center(width()/2, height()/2);

	p.translate(center);
    p.save();
    qreal angleStep = 30;
    qreal correction_x = 0, correction_y = 0;
    for (int i = 0; i < 12; ++i){
        p.save();
        p.rotate(i * angleStep);
        p.restore();
        if(i >= 4 && i < 6){
            correction_x += 5;
            correction_y += 5;
        }
//        if(i >= 6 && i < 8){

//        }
        if(i == 6){
            correction_x -= 5;
            correction_y -= 5;
        }
        if(i == 8){
            correction_y -= 10;
            correction_x += 10;
        }
        if (i == 11){
            correction_x = 0;
        }
        double xpos=(110+correction_x)*qCos((i * angleStep)/360.*2.*M_PI);
        double ypos=(110+correction_y)*qSin((i * angleStep)/360.*2.*M_PI);
        p.drawText(xpos, ypos, QString::number((i+2)%12+1));

    }

    p.restore();
    p.setPen(Qt::black);
    p.drawEllipse(-100,-100,200,200);

    // seconds
    p.save();
    p.rotate((_seconds - 30) * 6);
    p.scale(10,10);
    QPen arrow(Qt::blue);
    arrow.setWidth(0);
    p.setPen(arrow);
	drawArrow(p);
    p.restore();

    //minutes
    p.save();
    p.rotate(_minutes * 6);
    p.scale(8,8);
    p.setPen(arrow);
    drawArrow(p);
    p.restore();
    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0)
            p.drawLine(92, 0, 96, 0);
        p.rotate(6.0);
    }

    //hours
    p.save();
    p.rotate(_hours * 6);
    p.scale(6,6);
    p.setPen(arrow);
    drawArrow(p);
    p.restore();
    for (int j = 0; j < 12; ++j) {
        p.drawLine(88, 0, 96, 0);
        p.rotate(30.0);
    }
}

