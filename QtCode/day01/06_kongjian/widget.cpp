#include "widget.h"
#include "ui_widget.h"
#include <QStringList>
#include <QCompleter>
#include <QLabel>
#include <QMovie>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
   // ui->lineEdit->setEchoMode(QLineEdit::Password);

    QStringList list;
    list << "jfdif" << "Jjdjhf" << "jit";

    QCompleter *com = new QCompleter(list, this) ;
    com->setCaseSensitivity(Qt::CaseInsensitive);

    ui->lineEdit->setCompleter(com);
    ui->lineEdit->setTextMargins(10,10,20,4);
    ui->label->setText("fdf");
    ui->label_2->setPixmap(QPixmap("://Screenshot from 2020-02-20 16-03-33.png"));
    ui->label_2->setScaledContents(true);

    QMovie *movie = new QMovie("://Screenshot from 2020-02-20 16-03-33.gif");
    ui->label_3->setMovie(movie);
    movie->start();

    ui->label_4->setText("<h1><a href=\"https://www.baidu.com\">百度一下</a></h1>");
    ui->label_4->setOpenExternalLinks(true);

    ui->lcdNumber->display(143);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_released()
{
    static int i = 0;
    i = ++i % 4;
    ui->stackedWidget->setCurrentIndex(i);
}
