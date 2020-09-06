#ifndef SMALLWIDGET_H
#define SMALLWIDGET_H

#include <QWidget>

namespace Ui {
class smallWidget;
}

class smallWidget : public QWidget
{
    Q_OBJECT

public:
    explicit smallWidget(QWidget *parent = 0);
    ~smallWidget();

    //自己添加的成员函数
    void setNum(int num);
    int getNum();

private:
    Ui::smallWidget *ui;
};

#endif // SMALLWIDGET_H
