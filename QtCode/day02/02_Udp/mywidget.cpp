#include "mywidget.h"
#include "ui_mywidget.h"
#include <QHostAddress>


MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    udp = new QUdpSocket(this);

    setWindowTitle("Udp");

    udp->bind(8888,QAbstractSocket::ShareAddress);

    //组播地址
    //udp->bind(QHostAddress::AnyIPv4, 8888);
    //udp->joinMulticastGroup(QHostAddress("224.0.0.2"));


    connect(udp, &QUdpSocket::readyRead,
            [=]()
            {
                char buf[1024] = {0};
                QHostAddress cliadd;
                quint16 port;
                qint64 len = udp->readDatagram(buf, sizeof(buf), &cliadd, &port );
                if (len > 0)
                {
                    QString a = QString("[%1:%2] %3").arg(cliadd.toString()).arg(port).arg(buf);

                    ui->textEdit->append(a);
                }
            }
            );
}

MyWidget::~MyWidget()
{
    delete ui;
}


void MyWidget::on_Buttonsend_clicked()
{
    //获取对方的ｉｐ和端口号。
    QHostAddress ip = QHostAddress(ui->lineEditip->text());
    quint16 port = ui->lineEditport->text().toInt();

    QString str = ui->textEdit->toPlainText();
    QByteArray array = str.toUtf8();
    //QString转换成ｃｈａｒ* 使用ｔｏｕｔｆ８
    udp->writeDatagram(array, ip, port);


}

void MyWidget::on_pushButton_2_clicked()
{
    udp->disconnectFromHost();
    udp->close();
}
