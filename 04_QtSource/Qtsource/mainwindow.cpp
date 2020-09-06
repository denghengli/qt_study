#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //使用添加的QT资源 ":+前缀名:文件名"
    ui->actionNew->setIcon(QIcon(":/image/1.png"));
    ui->actionOpen->setIcon(QIcon(":/image/WIN_20191207_14_42_30_Pro.jpg"));

}

MainWindow::~MainWindow()
{
    delete ui;
}
