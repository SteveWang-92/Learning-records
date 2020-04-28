#include "mywidget.h"
#include "ui_mywidget.h"
#include <QFile>
#include <QFileDialog>
#include <QString>
#include <QFileInfo>
#include <QtDebug>
#include <QDataStream>




myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::myWidget)
{
    ui->setupUi(this);
}

myWidget::~myWidget()
{
    delete ui;
}


void myWidget::on_pushButtonread_released()
{
    QString path = QFileDialog::getOpenFileName(this, "open", "../", "TXT(*.txt);;"
                                                                     "CPP(*.cpp)");

    if (path.isEmpty()==false)
    {
        QFile file(path);
        bool isOk = file.open(QIODevice::ReadOnly);
        if (isOk == true)
        {
//第一种方法
//                QByteArray byte = file.readAll();
//                //默认只识别ＵＴＦ８
//                ui->textEdit->setText(byte);
//第二种
            QByteArray byte;
            while(file.atEnd() == false)
            {
             byte += file.readLine();
            }
            ui->textEdit->setText(byte);
        }
       file.close();



    }
}

void myWidget::on_pushButtonwrite_clicked()
{

    QString savepath =  QFileDialog::getSaveFileName(this, "save", "../","TXT(*.txt);;"
                                                "CPP(*.cpp)");

    if (savepath.isEmpty() == false)
    {
        QFile file;
        file.setFileName(savepath);
        bool isOk = file.open(QIODevice::WriteOnly);
        if (isOk == true)
        {
            QString str = ui->textEdit->toPlainText();
            file.write(str.toUtf8());
            //file.write(str.toLocal8Bit());
            //QString -> C++ String ->char *
            //
            //file.write(str.toStdString().data());
        }
        file.close();

        //QFileInfo info(savepath);
//        qDebug() << info.ownerId();
    }
}
