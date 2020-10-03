#ifndef CLOCK_H
#define CLOCK_H
#include <clockform.h>
#include <QWidget>

class Clock : public QWidget
{
	Q_OBJECT
	public:
        Clock(QWidget* parent = nullptr);
        friend ClockForm;
		void paintEvent(QPaintEvent*);
        //void timerEvent(QTimerEvent*);

	private:
		int _hours; 
		int _minutes; 
		int _seconds; 
};


#endif 
