#include "timerwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TimerWidget w;
    w.show();
    return a.exec();
}
