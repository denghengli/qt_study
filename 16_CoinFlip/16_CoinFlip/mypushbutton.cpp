#include "mypushbutton.h"
#include "QDebug"
#include "QPropertyAnimation"

//构造函数,参数：正常显示的图片路径 按下后显示的图片路径
MyPushbutton::MyPushbutton(QString normalImg, QString pressImg)
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pix;
    bool ret = pix.load(normalImgPath);
    if (!ret){
        qDebug() <<"图片加载失败";
        return;
    }

    //设置图片固定大小
    this->setFixedSize(pix.width(), pix.height());

    //设置不规则图片的样式
    this->setStyleSheet("QPushButton{border:0px}");

    //设置图标
    this->setIcon(pix);

    //设置图标大小
    this->setIconSize(QSize(pix.width(), pix.height()));
}

//向下跳
void MyPushbutton::zoom1()
{
    //创建动态对象
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    //设置动画时间间隔
    animation->setDuration(100);
    //起始位置
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}

//向上跳
void MyPushbutton::zoom2()
{
    //创建动态对象
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    //设置动画时间间隔
    animation->setDuration(100);
    //起始位置
    animation->setStartValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}


void MyPushbutton::mousePressEvent(QMouseEvent *e)
{
    if (this->pressImgPath != "")//传入的按下按钮不为空,表示需要切换图片
    {
        QPixmap pix;
        bool ret = pix.load(this->pressImgPath);
        if (!ret){
            qDebug() <<"图片加载失败";
            return;
        }

        //设置图片固定大小
        this->setFixedSize(pix.width(), pix.height());

        //设置不规则图片的样式
        this->setStyleSheet("QPushButton{border:0px}");

        //设置图标
        this->setIcon(pix);

        //设置图标大小
        this->setIconSize(QSize(pix.width(), pix.height()));
    }

    //让父类执行其他内容
    return QPushButton::mousePressEvent(e);
}

void MyPushbutton::mouseReleaseEvent(QMouseEvent *e)
{
    if (this->pressImgPath != "")//传入的按下按钮不为空,表示按下的时候切换图片了,弹起的时候需要切换回去
    {
        QPixmap pix;
        bool ret = pix.load(this->normalImgPath);
        if (!ret){
            qDebug() <<"图片加载失败";
            return;
        }

        //设置图片固定大小
        this->setFixedSize(pix.width(), pix.height());

        //设置不规则图片的样式
        this->setStyleSheet("QPushButton{border:0px}");

        //设置图标
        this->setIcon(pix);

        //设置图标大小
        this->setIconSize(QSize(pix.width(), pix.height()));
    }

    //让父类执行其他内容
    return QPushButton::mouseReleaseEvent(e);
}
































