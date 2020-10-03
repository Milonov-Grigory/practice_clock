#ifndef CLOCKFORM_H
#define CLOCKFORM_H

#include <QWidget>

namespace Ui {
class ClockForm;
}

class ClockForm : public QWidget
{
    Q_OBJECT

public:
    explicit ClockForm(QWidget *parent = nullptr);
    void timerEvent(QTimerEvent*);
    ~ClockForm();

private:
    Ui::ClockForm *ui;
};

#endif // CLOCKFORM_H
