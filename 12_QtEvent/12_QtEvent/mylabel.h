#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QEvent>
#include <QMouseEvent>

class mylabel : public QLabel
{
    Q_OBJECT
public:
    explicit mylabel(QWidget *parent = 0);


protected:
    virtual void enterEvent(QEvent *event);//鼠标进入事件 虚函数重写
    virtual void leaveEvent(QEvent *event);//鼠标离开事件 虚函数重写

    virtual void mouseMoveEvent(QMouseEvent * ev);//鼠标移动事件 虚函数重写
    virtual void mousePressEvent(QMouseEvent * ev);//鼠标按下事件 虚函数重写
    virtual void mouseReleaseEvent(QMouseEvent * ev);//鼠标释放事件 虚函数重写

    //重写event事件分发器，拦截鼠标按下事件
    bool event(QEvent *e);

signals:

public slots:
};

#endif // MYLABEL_H
