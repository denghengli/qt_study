#include "widget.h"
#include "QPushButton"
#include "qstring.h"

/*
    实现功能：
    1、下课后，老师触发一个信号，饿了，学生响应信号，请吃饭
*/

/*
    拓展：
    1、信号可以连接信号
    2、一个信号可以连接多个槽函数
    3、多个信号可以连接同一个槽函数
    3、信号和槽参数、类型必须一一对应
    4、信号的参数个数可以多于槽的参数个数，反之则不可以
    5、QT4版本以前的信号和槽连接方式 connect(tc,SIGNAL(hungry()),st,SLOT(treat()))
       QT4版本优点：参数直观，缺点：类型不做检测
*/
void Widget::class_over()
{
    //触发老师饿了的信号
    //emit tc->hungry();

    emit tc->hungry("宫保鸡丁");
}

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    //1、创建一个老师对象和学生对象
    this->st = new student;
    this->tc = new teacher;
    this->resize(800,480);

    //2、建立连接  无参信号和槽的链接
    //connect(tc,&teacher::hungry,st,&student::treat);

    //2、建立连接  有参参信号和槽的链接,通过函数指针指向要使用的信号和槽
//    void (teacher:: *teachersingal)(QString) = &teacher::hungry;
//    void (student:: *studentsolt)(QString) = &student::treat;
//    connect(tc,teachersingal,st,studentsolt);
    void (teacher:: *teachersingal)(void) = &teacher::hungry;
    void (student:: *studentsolt)(void) = &student::treat;
    //connect(tc,teachersingal,st,studentsolt);
    connect(tc,SIGNAL(hungry()),st,SLOT(treat()));//QT4版本

    //3、创建按钮
    QPushButton *btn = new QPushButton("下课",this);
    btn->resize(100,50);

    //4、调用触发信号
    //connect(btn,&QPushButton::clicked,this,&Widget::class_over);
    //信号连接信号
    connect(btn,&QPushButton::clicked,tc,teachersingal);
    //disconnect(tc,teachersingal,st,studentsolt);//断开连接
}

Widget::~Widget()
{

}
