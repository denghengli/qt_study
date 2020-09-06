#include "student.h"
#include <QDebug>

student::student(QObject *parent) : QObject(parent)
{

}

void student::treat()
{
    qDebug() <<"请老师吃饭";
}

void student::treat(QString foodNme)
{
    qDebug() <<"老师要吃:";
    //QString -> char*
    //qDebug() <<foodNme.toStdString().c_str();
    qDebug() <<foodNme.toUtf8().data();
}


















