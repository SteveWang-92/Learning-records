#include "mywidget.h"
//QApplication应用程序类
//Ｑｔ头文件没有.ｈ
//头文件和类名一样
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    w.show();
    return a.exec();
}
