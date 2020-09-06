#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include <QPaintEvent>
#include <playscene.h>

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = 0);
    PlayScene *play = NULL;//游戏场景对象

protected:
    void paintEvent(QPaintEvent *);//重写绘图事件,绘制背景

signals:
    void chooseSceneBack();//自定义信号,告诉主场景返回了

public slots:
};

#endif // CHOOSELEVELSCENE_H
