#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setStyleSheet("QLabel {color:red;"
                             "background-color:rgb(100,200,45)};");

//    ui->label->setStyleSheet("QLabel {color:red;"
//                             "background-color:rgb(100,200,45)};");
}

MainWindow::~MainWindow()
{
    delete ui;
}

