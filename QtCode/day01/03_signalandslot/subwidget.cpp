#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    b = new QPushButton(this);
    b->setText("切换界面");
    b->show();
    resize(400,300);
    connect(b , &QPushButton::released, this ,&SubWidget::sendSignal);
}

void SubWidget::sendSignal()
{
    emit mySignal();
    emit mySignal(250,"aa你好啊");
}
