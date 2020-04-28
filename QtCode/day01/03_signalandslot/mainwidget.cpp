#include "mainwidget.h"
#include <QPushButton>


MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    b1.setParent(this);
    b1.setText("dfd");
    b1.move(100,200);;
    b2 = new QPushButton(this);
    b2->setParent(this);
    b2->setText("hahh");

    connect(&b1, &QPushButton::pressed, this, &MainWidget::close);
    /*信号发出者（指针），＆信号发出者类名：：信号名字，　信号接受者（指针），＆信号接受者类名：：槽函数
信号和槽函数对应的就是ｓｉｇｎａｌ以及ｓｌｏｔ
*/
    /*自定义槽
     * 自定义槽函数需要与信号的一致（参数和返回值）
*/
    connect(b2, &QPushButton::released, this, &MainWidget::myslot);
    connect(b2, &QPushButton::released, &b1 , &QPushButton::hide);
    /*一个信号可以对应多个处理
     * 信号：短信
     * 槽函数：接受短信的手机
*/
/*b2本来就是一个指针了
 *
*/
   //setWindowTitle("boss");
   this->setWindowTitle("laada");

   b3 = new QPushButton(this);
   b3->setText("切换窗口");
   b3->move(200,200);

   connect(b3, &QPushButton::released, this, &MainWidget::changeWindow);


 //  w->show();


  //利用到函数指针
   //进行相同函数名的信号之间的区分。槽函数也是一样
  void (SubWidget::*funsignal)() = &SubWidget::mySignal;
  connect(&w, funsignal, this , &MainWidget::dealsignal);

  void (SubWidget::*fun2signal)(int ,QString) = &SubWidget::mySignal;
  connect(&w, fun2signal, this , &MainWidget::dealsig);


//QT4信号链接
//ＱＴ４槽函数必须有ｓｌｏｔｓ：关键字来修饰
//所以尽量用ＱＴ５，主要是在信号重载的时候，需要进行信号的区分，使用不同的指针来指代不同的
//   信号


//Lambda表达式，配合信号一起使用非常方便，匿名函数对象
//  C++11的新特性，所以需要在项目文件中　CONFIG += c++11
  QPushButton *b4 = new QPushButton(this);
  b4->setText("lambda");
  b4->show();
  b4->move(250,250);
  int a =10;
  connect(b4, &QPushButton::released,
          //＝的作用，将外部所有的局部变量以及类成员全部　值　传递进ｌａｍｂｄａ函数
          //&的作用，将外部所有的局部变量 引用符号　传递进ｌａｍｂｄａ函数
          //但是尽量用值传递,不然会出内存方面的问题。
          //并且是只读的方式，除非添加ｍｕｔａｂｌｅ
          //（）中传递的是参数，｛｝这里是函数体
          //也可以
          [=]() mutable
            {
            qDebug() << 132 << a;
            b4->setText("改变了吧");
            }
  );




  resize(400, 300);
}

void MainWidget::myslot()
{
    b2->setText("myslot");
}

void MainWidget::changeWindow()
{
    //子窗口显示
    //w=new SubWidget();
     w.show();
    this->hide();

}

void MainWidget::dealsignal()
{
    w.hide();
    this->show();
}


void MainWidget::dealsig(int a, QString str)
{
    qDebug() << a << str.toUtf8().data() ;
    //转换Ｑ字节数组，转换成char*
}


/*函数指针
 * void fun()
 *
 * void (*p)() = fun;指向函数的指针
 *
 *void fun(int)
 *
 * void (*p)(int) = fun;指向函数的指针


*/

MainWidget::~MainWidget()
{
}
