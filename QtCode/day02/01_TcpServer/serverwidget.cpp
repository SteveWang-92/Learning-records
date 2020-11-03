#include "serverwidget.h"
#include "ui_serverwidget.h"
#include <QString>

ServerWidget::ServerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerWidget)
{
    ui->setupUi(this);

    tcpServer = nullptr;
    tcpSocket = nullptr;


    //监听套接字，让父对象自动回收空间。
    tcpServer = new QTcpServer(this);

    tcpServer->listen(QHostAddress::Any, 8888);

    setWindowTitle("Tcp Server");

//注意，这里的初始构造函数只初始化了tcpServer指针，但是并没有初始化tcpSocket指针，
 //tcpSocket指针只在信号发出到槽函数的时候，才会初始化。
    //所以在进行其余的按钮操作的时候，需要检查tcpSocket指针是不是空指针（野指针）
    connect(tcpServer, &QTcpServer::newConnection,
            [=]()
            {
                //取出建立好的套接字
                tcpSocket = tcpServer->nextPendingConnection();
                //获取对方的Ｉｐ和端口。
                //QString IP = tcpSocket->peerAddress().toIPv4Address();
                QString ip = tcpSocket->peerAddress().toString();
                qint16 port = tcpSocket->peerPort();
                QString tmp = QString("[%1:%2]:成功连接").arg(ip).arg(port);

                ui->textEditread->setText(tmp);


                //注意，为什么要放在里面，因为如果放在外面，tcpSocket还是个野指针，
                //并没有东西，所以程序会　　程序异常结束
                connect(tcpSocket, &QTcpSocket::readyRead,
                        [=]()
                        {
                            //从通信套接字中取出内容。
                            QByteArray array =  tcpSocket->readAll();

                            ui->textEditread->append(array);
                        }
                        );
            }
            );
}

ServerWidget::~ServerWidget()
{
    delete ui;
}


void ServerWidget::on_Buttonsend_clicked()
{
    //获取编辑区内容
    if (nullptr == tcpSocket)   //做判断啊　！！！！！
    {
        return;
    }
    QString str =  ui->textEditwrite->toPlainText();
    tcpSocket->write(str.toUtf8().data());
    //QString转换成ｃｈａｒ*;  str.toUtf8().data()
}

void ServerWidget::on_Buttonclose_clicked()
{
    if (nullptr == tcpSocket)
    {
        return;
    }
    //主动和客户端断开链接
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    tcpSocket = nullptr;
}
