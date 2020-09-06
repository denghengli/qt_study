#ifndef MYCOIN_H
#define MYCOIN_H

#include <QWidget>
#include <QPushButton>
#include <QTimer>
#include <QMouseEvent>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyCoin(QWidget *parent = 0);
    MyCoin(QString btnImg);
    int posX;//横坐标
    int posY;//纵坐标
    bool flag;//正反面标志
    bool isAnimation  = false;//执行动画标志,这里一定要赋初值!!!
    bool isWin = false;//判断是否胜利的标志
    int min = 1;//金币位置
    int max = 8;//银币位置

    void changeFlag();
    QTimer *timer1;//正面翻反面(金币翻成银币)的定时器
    QTimer *timer2;//反面翻正面(银币翻成金币)的定时器

protected:
    //重写按下事件,只有在isAnimation为false时执行,避免翻转过程中连续点击按钮
    virtual void mousePressEvent(QMouseEvent *e);

signals:

public slots:
};

#endif // MYCOIN_H
