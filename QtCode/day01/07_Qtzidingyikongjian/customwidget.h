#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QTimerEvent>
#include <QLabel>


class CustomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CustomWidget(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event);//timerEvent其实是在QObject:中，所以可能需要找，
    //有时不一定自动补全里面都有。
private:
    QLabel mylabe;

signals:

};

#endif // CUSTOMWIDGET_H
