#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>
#include <QPolygon>
#include <QPoint>
#include <QObject>
#include <QMatrix>
#include <QRect>
#include <QLabel>
#include <QFont>

#include <cmath>

class Clock : public QWidget
{
	Q_OBJECT
	public:
		Clock(QWidget* parent = 0);

		void paintEvent(QPaintEvent*);
        void timerEvent(QTimerEvent*);

	private:
		int _hours; 
		int _minutes; 
        int _seconds;

        QPolygon _hoursArrow;
        QPolygon _minutesArrow;
        QPolygon _secondsArrow;

        qreal _hoursArrowAngle;
        qreal _minutesArrowAngle;
        qreal _secondsArrowAngle;


};


#endif 
