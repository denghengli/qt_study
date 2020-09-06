#include "mypushbutton.h"
#include <QDebug>

myPushButton::myPushButton(QWidget *parent) : QPushButton(parent)
{
    qDebug() <<"自己button的构造函数";
}

myPushButton::~myPushButton()
{
    qDebug() <<"自己button的析构函数";
}
