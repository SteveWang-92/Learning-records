#include "customwidget.h"
#include <QtDebug>


CustomWidget::CustomWidget(QWidget *parent) : QWidget(parent)
{
    QSpinBox *spin = new QSpinBox(this);
    QSlider *slider = new QSlider(this);

    QLabel *label = new QLabel(this);
    label->setText("时间");

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(spin);
    layout->addWidget(slider);
    mylabe.setParent(this);
    mylabe.show();
    startTimer(100);



    //static_cast<void (QSpinBox::*)(int)>　强制类型转换，尖括号里面是函数指针，第一个是函数名字
    //第二个ｉｎｔ是参数。
    connect(spin, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            slider,&QSlider::setValue);

    connect(slider, &QSlider::valueChanged, spin, &QSpinBox::setValue);



}

void CustomWidget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << (char)event->key() ;

}

void CustomWidget::timerEvent(QTimerEvent *event)
{
    static int sec = 0;
    this->mylabe.setText(QString("time out %1").arg(sec++));
}
