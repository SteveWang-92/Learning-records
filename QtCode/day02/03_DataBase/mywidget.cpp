#include "mywidget.h"
#include "ui_mywidget.h"
#include <QtDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlDatabase>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    qDebug() << QSqlDatabase::drivers();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../info.db");



    //db.setHostName("127.0.0.1");//数据库服务器ＩＰ
    //db.setHostName("root");//数据库用户名
    //db.setPassword("112358");//数据库密码
    //db.setDatabaseName("info");//使用哪个数据库

    if (!db.open())
    {
        QMessageBox::warning(this,"错误", db.lastError().text());
        return;
    }

    QSqlQuery query;

    query.exec("DROP TABLE students");        //先清空一下表
    query.exec("CREATE TABLE students ("
                       "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                       "name VARCHAR(40) NOT NULL, "
                       " score INTEGER NOT NULL, "
                       "class VARCHAR(40) NOT NULL)");
                    //创建一个students表,标题分别为id、name、score、class
    query.exec("INSERT INTO students (name, score,class) "
                   "VALUES ('小张', 85, '初2-1班')");
                  //向students表里的(name, score,class)标题下插入一项数据'小张', 85, '初2-1班'
    QStringList names;
    names<<"小A"<<"小B"<<"小C"<<"小D"<<"小E"<<"小F"<<"小G"
               <<"小H"<<"小I"<<"小G"<<"小K"<<"小L"<<"小M"<<"小N";

    QStringList clases;
    clases<<"初1-1班"<<"初1-2班"<<"初1-3班"<<"初2-1班"
             <<"初2-2班"<<"初2-3班"<<"初3-1班"<<"初3-2班"<<"初3-3班";

    //query.exec("DROP TABLE students");        //先清空一下表
    query.exec("CREATE TABLE students ("
                       "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                       "name VARCHAR(40) NOT NULL, "
                       " score INTEGER NOT NULL, "
                       "class VARCHAR(40) NOT NULL)");
                    //创建一个students表

        query.prepare("INSERT INTO students (name, score,class) "
                      "VALUES (:name, :score, :class)");
                        //为每一列标题添加绑定值

        foreach (QString name, names)       //从names表里获取每个名字
        {
            query.bindValue(":name", name);                      //向绑定值里加入名字
            query.bindValue(":score", (qrand() % 101));      //成绩
            query.bindValue(":class", clases[qrand()%clases.length()] );    //班级
            query.exec();               //加入库中
         }
        query.exec("SELECT * FROM students WHERE score >= 60 AND score <= 90;");
        while(query.next())
        {
            QString id = query.value(0).toString();
            QString name = query.value(1).toString();
            QString score = query.value(2).toString();
            QString classs = query.value(3).toString();

            qDebug()<<id<<name<<score<<classs;
        }

}

MyWidget::~MyWidget()
{
    delete ui;
}

