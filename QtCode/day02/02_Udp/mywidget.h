#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QUdpSocket>


QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private slots:
    void on_Buttonsend_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MyWidget *ui;

    QUdpSocket *udp;
};
#endif // MYWIDGET_H
