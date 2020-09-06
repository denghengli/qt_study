#include "widget.h"
#include "ui_widget.h"
#include "QDebug"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //通过按钮设置和获取自定义控件的值
    connect(ui->btn_get, &QPushButton::clicked, [=](){
        qDebug() <<ui->mywidget->getNum();
    });
    connect(ui->btn_set, &QPushButton::clicked, [=](){
        ui->mywidget->setNum(50);
    });
}

Widget::~Widget()
{
    delete ui;
}
