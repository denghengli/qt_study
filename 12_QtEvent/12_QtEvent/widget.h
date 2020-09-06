#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    int timer1_id;//有多个定时器时,通过定时器ID来识别
    int timer2_id;

protected:
    //重写定时器事件
    virtual void timerEvent(QTimerEvent *ev);


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
