#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h"
#include <QDebug>


class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    void myslot();
    void changeWindow();
    void dealsignal();
    void dealsig(int ,QString);
private:
    QPushButton b1;
    QPushButton *b2;
    QPushButton *b3;
    SubWidget w;
};
#endif // MAINWIDGET_H
