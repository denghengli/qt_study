#include "widget.h"
#include "QPushButton"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(800,480);
    this->setWindowTitle("练习窗口");

    Widget *w1 = new Widget(this);
    w1->resize(500,500);

    QPushButton *btn1 = new QPushButton("打开", this);
    btn1->move(100,100);
    btn1->resize(100,50);
    connect(btn1, &QPushButton::clicked, this, [=](){
        //w1->show();
        //btn1->setText("关闭");
//        Widget *w1 = new Widget(this);
//        w1->resize(500,500);
        w1->show();
    });

    QPushButton *btn2 = new QPushButton("关闭", this);
    btn2->move(100,300);
    btn2->resize(100,50);
}

Widget::~Widget()
{

}
