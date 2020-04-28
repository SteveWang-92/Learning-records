#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QSqlTableModel>
QT_BEGIN_NAMESPACE
namespace Ui { class myWidget; }
QT_END_NAMESPACE

class myWidget : public QWidget
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = nullptr);
    ~myWidget();

private slots:
    void on_Buttonadd_clicked();

    void on_Buttonyes_clicked();

    void on_Buttoncancel_clicked();

    void on_Buttondel_clicked();

    void on_Buttonsearch_clicked();

private:
    Ui::myWidget *ui;
    QSqlTableModel *model;

};
#endif // MYWIDGET_H
