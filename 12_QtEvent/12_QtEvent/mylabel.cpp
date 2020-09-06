#include "mylabel.h"
#include "QDebug"
#include "QString"

mylabel::mylabel(QWidget *parent) : QLabel(parent)
{

}

//鼠标进入事件
void mylabel::enterEvent(QEvent *event)
{
    qDebug() <<"鼠标进入";
}

//鼠标离开事件
void mylabel::leaveEvent(QEvent *event)
{
    qDebug() <<"鼠标离开";
}

//鼠标移动事件 虚函数重写
 void mylabel::mouseMoveEvent(QMouseEvent * ev)
{
    qDebug() <<"鼠标移动";
}

//鼠标按下事件 虚函数重写
 void mylabel::mousePressEvent(QMouseEvent * ev)
{
    //格式化字符串
    if (ev->button() == Qt::LeftButton) //左键按下判断
    {
        QString str = QString("鼠标按下了,x=%1,y=%2").arg(ev->x()).arg(ev->y());
        qDebug() <<str.toUtf8().data();
    }
}

//鼠标释放事件 虚函数重写
 void mylabel::mouseReleaseEvent(QMouseEvent * ev)
{
    qDebug() <<"鼠标释放";
}


 //重写event事件分发器，拦截鼠标按下事件,实际工程并不会拦截!!!!!
 bool mylabel::event(QEvent *e)
 {
    //自己处理按钮 按下事件
    if (e->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *ev = dynamic_cast<QMouseEvent *>(e);//类型转换,将父类对象转为子类对象
        QString str = QString("Event函数中，鼠标按下了,x=%1,y=%2").arg(ev->x()).arg(ev->y());
        qDebug() <<str.toUtf8().data();

        return true;//表示该事件已经被处理了,true代表用户自己处理这个事件 不想下分发
    }

    //其他事件交给父类处理，默认处理
    return QLabel::event(e);
 }


















