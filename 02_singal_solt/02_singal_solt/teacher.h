#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>
#include "qstring.h"

class teacher : public QObject
{
    Q_OBJECT
public:
    explicit teacher(QObject *parent = 0);

//添加自定义信号:
//1、只需要声明，不需要实现，返回值是void
//2、可以有参数，可以重载
signals:
    void hungry();
    void hungry(QString foodName);

public slots:
};

#endif // TEACHER_H
