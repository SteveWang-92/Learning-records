#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    //主窗口的ｍｏｖｅ相当于主屏幕，第一个数值是横坐标，第二个是纵坐标。
    move(100,100);
}

MyWidget::~MyWidget()
{
}

