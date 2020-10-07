#include <QApplication>
#include <clockwidget.h>

int main(int ac, char* av[])
{
    QApplication a(ac, av);

    Clock theClock; theClock.show();

    QObject::connect(
            &a, SIGNAL(lastWindowClosed()),
            &a, SLOT(quit())
            );

    return a.exec();
}
