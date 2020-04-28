#include "mywindow.h"
#include "ui_mywindow.h"
#include <QBuffer>//内存文件


MyWindow::MyWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyWindow)
{
    ui->setupUi(this);

    QBuffer memFile;
    memFile.open(QIODevice::ReadOnly);

    memFile.write("fdfd");

    memFile.write("42432");



}

MyWindow::~MyWindow()
{
    delete ui;
}

