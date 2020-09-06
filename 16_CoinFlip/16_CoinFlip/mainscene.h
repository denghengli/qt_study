#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <QPaintEvent>
#include "chooselevelscene.h"

namespace Ui {
class mainscene;
}

class mainscene : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainscene(QWidget *parent = 0);
    ~mainscene();

    ChooseLevelScene *chooseScene = NULL;//选择场景

protected:
    //重写paintEvent事件，画背景图
    virtual void paintEvent(QPaintEvent *);

private:
    Ui::mainscene *ui;
};

#endif // MAINSCENE_H
