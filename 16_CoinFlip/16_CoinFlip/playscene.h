#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QPaintEvent>
#include <mycoin.h>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    PlayScene(int levelNum);
    bool isWin = false;//判断是否胜利的标志
    int levelIndex;//记录选择的关卡
    int gameArray[4][4];//二维数组维护每个关卡的具体数据,是正面还是反面
    MyCoin *coinbtns[4][4];//记录关卡中金币句柄

protected:
    void paintEvent(QPaintEvent *);

signals:
    void chooseSceneBack();//自定义信号,告诉选择场景返回了

public slots:
};

#endif // PLAYSCENE_H
