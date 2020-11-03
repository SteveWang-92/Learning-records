#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDataStream>
#include <QFile>
#include <QtDebug>
#include <QTextStream>

//如果ｑｄｅｂｕｇ很烦，那么可以定义ｃｏｕｔ。和ｃ＋＋中一样
//这样就可以了
//很方便
//#define cout qDebug() << "[" << _FILE_ << ":" << _LINE_ << "]"


MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    MyWidget::setWindowTitle("wode ");
    writeData();
    readData();
}

MyWidget::~MyWidget()
{
    delete ui;
}


void MyWidget::writeData()
{
    QFile file("../test.txt");
    bool isOk = file.open(QIODevice::WriteOnly);
    if (isOk == true)
    {
        //创建数据流，和文件关联
        //往数据流中写数据，相当于往文件里面写数据。
        QDataStream stream(&file);
        stream << QString("fdjhjdhdf") << 787;

        file.close();
    }
}

void MyWidget::readData()
{
    QFile file("../test.txt");
    bool isOk = file.open(QIODevice::ReadOnly);
    if (isOk == true)
    {
        //创建数据流，和文件关联
        //往数据流中读取数据，相当于往文件里面读取写数据。
        QDataStream stream(&file);
        QString str;
        int a;
        stream >> str >> a;
        qDebug() << str << a;
 //       cout << str << a ;

        file.close();
    }
}

