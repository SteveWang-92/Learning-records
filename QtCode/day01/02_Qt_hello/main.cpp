#include <QApplication>
#include <QWidget>
#include <QPushButton>



int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QWidget w;    w.setWindowTitle("主要看气质");
    QPushButton b;
    b.setText("fjdk");
    b.setParent(&w);
    b.move(100,200);

    QPushButton c(&w);
    c.setText("+++");

  /*如果不指定父对象 ，对象和对象之间是独立的
    ａ指定ｂ为它的父对象，ａ在ｂ上面
    */

    w.show();




    app.exec();
}
