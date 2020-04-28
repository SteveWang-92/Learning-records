#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QWidget>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class TimerWidget; }
QT_END_NAMESPACE

class TimerWidget : public QWidget
{
    Q_OBJECT

public:
    TimerWidget(QWidget *parent = nullptr);
    ~TimerWidget();

private slots:
    void on_pushButtonstart_clicked();

    void on_pushButtonstop_clicked();

private:
    Ui::TimerWidget *ui;

    QTimer *m_timer;

};
#endif // TIMERWIDGET_H
