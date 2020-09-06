#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class student : public QObject
{
    Q_OBJECT
public:
    explicit student(QObject *parent = 0);

signals:

//添加自定义槽:
//1、早期的Qt版本必须写在public solts下，高版本可以写到public或全局下
//2、返回值是void，需要声明，也需要实现
//3、可以有参数，可以重载
public slots:
    void treat();
    void treat(QString foodNme);
};

#endif // STUDENT_H
