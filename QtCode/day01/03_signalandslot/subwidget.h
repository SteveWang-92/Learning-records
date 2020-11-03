#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>
class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);

    void sendSignal();
signals:
    void mySignal();
    void mySignal(int , QString);
    /*
     * 信号没有返回值。可以有参数
     * 必须有ｓｉｇｎａｌ参数来声明
     * 使用就是ｅｍｉｔ　ｍｙｓｉｇｎａｌ
*/

private:
    QPushButton *b;


};

#endif // SUBWIDGET_H
