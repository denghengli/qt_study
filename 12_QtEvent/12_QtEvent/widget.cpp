#include "widget.h"
#include "ui_widget.h"
#include "QTimer"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //定时器的第一种方法：通过定时器事件和重写定时器回调函数
    //启动定时器,周期单位ms
    //timer1_id = startTimer(1000);
    //timer2_id = startTimer(10000);

    //定时器的第二种方法：通过定时器类
    QTimer *timer = new QTimer(this);
    timer->start(500);
    connect(timer, &QTimer::timeout, [=](){
        static int num = 1;
        ui->label->setNum(num++);
    });
    //通过点击按钮停止定时器
    connect(ui->btn_stop, &QPushButton::clicked, [=](){
        if (timer->isActive())
            timer->stop();
        else
            timer->start(500);
    });


}

Widget::~Widget()
{
    delete ui;
}

//重写定时器事件回调函数
void Widget::timerEvent(QTimerEvent *ev)
{
    static int num = 1;

    if (ev->timerId() == timer1_id){
        ui->label->setNum(num++);
    } else if (ev->timerId() == timer2_id){
        num = 1;
    }
}
