#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#define cout qDebug() << "[" << _FILE_ << ":" << _LINE_ << "]"
QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

    void writeData();
    void readData();


private:
    Ui::MyWidget *ui;
};
#endif // MYWIDGET_H
