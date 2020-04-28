#include "mywidget.h"
#include "ui_mywidget.h"
#include <QTextStream>
#include <QFile>
#include <QDebug>



MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    writeData();
    readData();

}

MyWidget::~MyWidget()
{
    delete ui;
}


void MyWidget::writeData()
{
    QFile file("../demo.txt");
    bool isOk = file.open(QIODevice::WriteOnly);
    if (isOk)
    {
        QTextStream stream(&file);
        //stream.setCodec(GB18030);
        stream << "dhjfhd" <<" " << 520;
        file.close();
    }

}

void MyWidget::readData()
{
    QFile file("../demo.txt");
    bool isOk = file.open(QIODevice::ReadOnly);
    if (isOk)
    {
        QTextStream stream(&file);
        QString str;
        int a;
        stream >> str >> a;
        qDebug() << str << a;
        file.close();
    }
}
