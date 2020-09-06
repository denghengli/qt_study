#include "widget.h"
#include "ui_widget.h"
#include "QPainter"
#include "QTimer"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

//    //1、移动按钮来移动图片
//    connect(ui->btn_move, &QPushButton::clicked, [=](){
//        update();//如果要手动的调用绘图事件,用update更新
//    });

//    //2、通过定时器来移动图片
//    QTimer *timer = new QTimer(this);
//    //timer->start(1);
//    connect(timer, &QTimer::timeout, [=](){
//        update();
//    });
//    //通过点击按钮停止定时器
//    connect(ui->btn_stop, &QPushButton::clicked, [=](){
//        if (timer->isActive())
//            timer->stop();
//        //else
//            //timer->start(1);
//    });
}

Widget::~Widget()
{
    delete ui;
}

//绘图事件处理函数
void Widget::paintEvent(QPaintEvent *)
{
//    //实例化画家对象 this指定绘图设备
//    QPainter painter(this);

//    QPen pen(QColor(255,0,0));//设置笔的颜色
//    pen.setWidth(3);//设置笔的大小
//    pen.setStyle(Qt::DashLine);//设置笔的风格
//    painter.setPen(pen);//让画家使用这个笔

//    QBrush brush(Qt::Dense1Pattern);//设置画刷
//    painter.setBrush(brush);

//    //画椭圆
//    painter.drawEllipse(QPoint(100,100), 100, 50);



//    /********高级设置********/
//    QPainter painter(this);

//    //1、设置抗锯齿能力，效率较低
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(QPoint(100,200), 50, 50);

//    //2、移动画家
//    painter.drawRect(QRect(20,20,50,50));
//    painter.translate(100,0);//移动画家位置
//    painter.save();//保存画家状态
//    painter.drawRect(QRect(20,20,50,50));

    /*利用画家 画资源图片*/
    static int x = 0;
    QPainter painter(this);
    if (x > this->width())//超出了屏幕范围
    {
        x = 0;
    }
    painter.drawPixmap(x++,50,QPixmap(":/image/1.png"));
}














