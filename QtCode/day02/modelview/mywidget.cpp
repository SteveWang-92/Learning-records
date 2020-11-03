#include "mywidget.h"
#include "ui_mywidget.h"
#include <QSqlDatabase>
#include <QtDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRecord>



myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::myWidget)
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

    //设置模型
    model = new QSqlTableModel(this, db);
    model->setTable("students");

    ui->tableView->setModel(model);//把ｍｏｄｅｌ放在tableView

    model->select();//显示model的数据
//设置第一列名称为学号。
    model->setHeaderData(0, Qt::Horizontal, "学号");

//设置手动提交才生效
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //不允许修改

}

myWidget::~myWidget()
{
    delete ui;
}


void myWidget::on_Buttonadd_clicked()
{
    //添加空记录
    QSqlRecord record = model->record();


    //获取行号
    int row = model->rowCount();
    //record.setValue(0,row+1);//设置第一列为自动生成的东西
    model->insertRecord(row ,record);
}

void myWidget::on_Buttonyes_clicked()
{
    model->submitAll();
}

void myWidget::on_Buttoncancel_clicked()
{
    model->revertAll();//取消所有提交
    model->submitAll();//提交动作
}

void myWidget::on_Buttondel_clicked()
{
    //获取选中的模型
    QItemSelectionModel *select =  ui->tableView->selectionModel();

    //取出模型索引

    QModelIndexList  list = select->selectedRows();

    //删除所有选中行
    for (int i=0; i<list.size(); i++) {
        model->removeRow(list.at(i).row());
    }

}

void myWidget::on_Buttonsearch_clicked()
{

    //设置过滤条件
    QString name =  ui->lineEdit->text();

    //注意％１的单引号
    QString str = QString("name ='%1'").arg(name);

    model->setFilter(str);
    model->select();
}
