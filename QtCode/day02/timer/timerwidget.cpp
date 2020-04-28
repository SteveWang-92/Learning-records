#include "timerwidget.h"
#include "ui_timerwidget.h"

TimerWidget::TimerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TimerWidget)
{
    ui->setupUi(this);

    m_timer = new QTimer();

    connect(m_timer ,&QTimer::timeout,
            [=]()
    {
        static int i = 0;//i值会在编译的时候就设定，运行时不会改变，
        //不管有没有定义这个对象，都会存在这个值
        i++;
        ui->lcdNumber->display(i);
    }
            );
}

TimerWidget::~TimerWidget()
{
    delete ui;
}


void TimerWidget::on_pushButtonstart_clicked()
{
    if(m_timer->isActive() == false){
        m_timer->start(1000);
    }
}

void TimerWidget::on_pushButtonstop_clicked()
{
    if(m_timer->isActive() == true){
        m_timer->stop();
    }
}
