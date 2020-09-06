#include "mycoin.h"
#include "QString"
#include "QDebug"
#include "QPixmap"
#include "QPushButton"

//MyCoin::MyCoin(QWidget *parent) : QWidget(parent)
//{

//}


MyCoin::MyCoin(QString btnImg)
{
    QPixmap pix;
    bool ret = pix.load(btnImg);
    if (!ret)
    {
        QString str = QString("图片 %1 加载失败").arg(btnImg);
        qDebug() <<str;
        return;
    }

    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));

    //初始化定时器对象
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    //监听正面翻反面(金币翻成银币)的信号,并且翻转金币
    connect(timer1, &QTimer::timeout, [=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->min++);
        bool ret = pix.load(str);
        if (!ret){
            QString str = QString("图片 %1 加载失败").arg(str);
            qDebug() <<str;
            return;
        }
        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
        if (this->min > this->max)
        {
            this->min = 1;
            timer1->stop();
            this->isAnimation = false;
        }
    });

    //监听反面翻正面(银币翻成金币)的信号,并且翻转金币
    connect(timer2, &QTimer::timeout, [=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->max--);
        bool ret = pix.load(str);
        if (!ret){
            QString str = QString("图片 %1 加载失败").arg(str);
            qDebug() <<str;
            return;
        }
        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
        if (this->max < this->min)
        {
            this->max = 8;
            timer2->stop();//翻转8次后才停止,显示整个翻转的过程
            this->isAnimation = false;
        }
    });
}

//改变正反面的标志的方法
void MyCoin::changeFlag()
{
    if (this->flag)
    {
        timer1->start(30);
        this->flag = false;
        this->isAnimation = true;//翻转开始,定时器停止翻转结束
    }
    else
    {
        timer2->start(30);
        this->flag = true;
        this->isAnimation = true;
    }
}

//重写按下事件,只有在isAnimation为false时执行,避免翻转过程中连续点击按钮
//在执行中或胜利后不再执行点击事件
void MyCoin::mousePressEvent(QMouseEvent *e)
{
    if (this->isAnimation || this->isWin)
    {
        return;
    }
    else
    {
        QPushButton::mousePressEvent(e);//交给父类处理
    }
}


















