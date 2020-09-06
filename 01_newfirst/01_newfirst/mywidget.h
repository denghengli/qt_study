#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

/*
    1、命令规范：
        类名首字母大写，单词与单词之间首字母大写

    2、快捷键:
        ctrl + / 注释
        ctrl + r 运行
        ctrl + b 编译
        ctrl + 鼠标滚轮 缩放
        ctrl + f 查找
        ctrl + shift +上/下 整行移动
        F1 帮助文档
        G:\QT5.5.0\soft\5.5\mingw492_32\bin\assistant.exe 帮助文档
        ctrl + i 自动对齐
        F4 同名之间的.h和.cpp切换
*/

class myWidget : public QWidget
{
/*
#define Q_OBJECT \
public: \
    Q_OBJECT_CHECK \
    QT_WARNING_PUSH \
    Q_OBJECT_NO_OVERRIDE_WARNING \
    static const QMetaObject staticMetaObject; \
    virtual const QMetaObject *metaObject() const; \
    virtual void *qt_metacast(const char *); \
    virtual int qt_metacall(QMetaObject::Call, int, void **); \
    QT_WARNING_POP \
    QT_TR_FUNCTIONS \
private: \
    Q_DECL_HIDDEN_STATIC_METACALL static void qt_static_metacall(QObject *, QMetaObject::Call, int, void **); \
    struct QPrivateSignal {};
*/
    Q_OBJECT //允许类中使用信号和槽的机制

public:
    myWidget(QWidget *parent = 0);//有参构成函数
    ~myWidget();
};

#endif // MYWIDGET_H
