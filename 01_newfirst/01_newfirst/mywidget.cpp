#include "mywidget.h"
#include <QPushButton>
#include "mypushbutton.h"

myWidget::myWidget(QWidget *parent) : QWidget(parent)
{
    //创建第一个按钮
    QPushButton *btn = new QPushButton;
    //让btn依赖在myWidget窗口中
    btn->setParent(this);
    //显示文本
    btn->setText("第一个按钮");

    //创建第二个按钮
    QPushButton *btn2 = new QPushButton("第二个按钮", this);
    btn2->move(100,100);

    //创建第三个自己类按钮
    myPushButton *btn3 = new myPushButton;
    btn3->setText("自己的按钮");
    btn3->setParent(this);
    btn3->move(100,200);

    //重置窗口大小
    resize(600, 400);
    //设置固定窗口大
    setFixedSize(800,800);
    //设置窗口标题
    setWindowTitle("第一个窗口");

    //点击按钮关闭窗口
    //connect(信号的发送者，发送的具体信息，信号的接收者，信号的处理(槽))
    connect(btn3, &myPushButton::clicked, this, &myWidget::close);
}

myWidget::~myWidget()
{

}
