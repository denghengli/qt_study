#include "mywidget.h"
#include <QApplication> //应用程序类的头文件


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//应用程序对象，有且只有一个

    myWidget w;//窗口对象，它的父类是QWidget
    w.show();//调用show方法

    return a.exec();//让应用程序对象进入消息循环机制,让带吗阻塞在这里
}
