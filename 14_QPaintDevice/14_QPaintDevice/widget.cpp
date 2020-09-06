#include "widget.h"
#include "ui_widget.h"
#include "QPixmap"
#include "QImage"
#include "QPicture"
#include "QPainter"

Widget::Widget(QWidget *parent) :QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    //1、Pixmap作为绘图设备,专门为平台做了显示优化
    QPixmap pix(300,300);
    pix.fill(Qt::white);//填充背景色

    QPainter painter1(&pix);//声明画家

    QPen pen1(QColor(255,0,0));//设置笔的颜色
    pen1.setWidth(3);//设置笔的大小
    pen1.setStyle(Qt::DashLine);//设置笔的风格

    painter1.setPen(pen1);//让画家使用这个笔
    painter1.drawEllipse(QPoint(150,150), 100, 100);//画圆

    pix.save("H:/C++/QTProject/14_QPaintDevice/pix.png");//保存QPixmap至电脑硬盘


    //2、QImage作为绘图设置，可以对像素进行访问，功能比QPixmap强大
    QImage img(300,300,QImage::Format_RGB32);
    img.fill(Qt::white);//填充背景色

    QPainter painter2(&img);//声明画家

    QPen pen2(QColor(100,0,0));//设置笔的颜色
    pen2.setWidth(3);//设置笔的大小
    pen2.setStyle(Qt::DashLine);//设置笔的风格

    painter2.setPen(pen2);//让画家使用这个笔
    painter2.drawEllipse(QPoint(150,150), 100, 100);//画圆

    img.save("H:/C++/QTProject/14_QPaintDevice/img.png");//保存QPixmap至电脑硬盘



    //3、QPicture绘图设备，可以记录和重新绘图指令
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);//开始往pic上画
    painter.setPen(QPen(Qt::cyan));
    painter.drawEllipse(QPoint(150,150), 100, 100);
    painter.end();//结束画图

    pic.save("H:/C++/QTProject/14_QPaintDevice/pic");//保存到磁盘
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);//向Widget窗口绘画

    //利用QImage对像素进行修改
    QImage img;
    img.load("H:/C++/QTProject/14_QPaintDevice/img.png");
    //修改像素点
//    for(int i=10; i<20; i++)
//    {
//        for(int j=10; j<20; j++)
//        {
//            QRgb value = qRgb(255,0,0);
//            img.setPixel(i,j,value);
//        }
//    }
    painter.drawImage(100,0,img);

    //重现QPicture绘图指令
    QPicture pic;
    pic.load("H:/C++/QTProject/14_QPaintDevice/pic");
    painter.drawPicture(0,0,pic);
}















