#include <QApplication>
#include <clock_widget.h>
#include<clockform.h>
#include <QLabel>
int main(int ac, char* av[])
{
	QApplication a(ac, av);

//   Clock theClock;
//   QLabel testLable(&theClock);
//   testLable.setText("00:00:00");
//   testLable.setMargin(theClock.width()/2);
//   theClock.show();
    ClockForm form;
    form.show();
	QObject::connect(
			&a, SIGNAL(lastWindowClosed()),
			&a, SLOT(quit())
			);

	return a.exec();
}

