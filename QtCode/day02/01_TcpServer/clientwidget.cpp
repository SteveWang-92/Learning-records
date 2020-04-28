#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QHostAddress>
ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);


    setWindowTitle("TcpClient");
    tcpsocket = nullptr;
    tcpsocket = new QTcpSocket(this);

    connect(tcpsocket, &QTcpSocket::connected,
            [=]()
            {
                ui->textEditread->setText("成功和服务器建立链接");
            }
            );

    connect(tcpsocket, &QTcpSocket::readyRead,
            [=]()
            {
                //从通信套接字中取出内容。
                QByteArray array =  tcpsocket->readAll();

                ui->textEditread->append(array);
            }
            );


}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_Buttonconnect_clicked()
{

    QString ip = ui->lineEditIP->text();
    quint16 port = ui->lineEditport->text().toInt();

    tcpsocket->connectToHost(QHostAddress(ip), port, QIODevice::ReadWrite);

}
//    if (tcpsocket )


void ClientWidget::on_Buttonclose_clicked()
{
    //主动和客户端断开链接
    tcpsocket->disconnectFromHost();
    tcpsocket->close();

//    tcpsocket = nullptr;
}

void ClientWidget::on_Buttonsend_clicked()
{
    if (nullptr == tcpsocket)
    {
        return;
    }

    QString str = ui->textEditwrite->toPlainText();

    tcpsocket->write(str.toUtf8().data());

}
