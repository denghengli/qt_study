#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QDebug>
#include <QPushButton>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800,480);
    setWindowTitle("记事本");

    //1、创建菜单栏(set...)
    QMenuBar *menubar = new QMenuBar(this);
    setMenuBar(menubar);//将菜单栏放入到窗口中
    //1.1、创建菜单
    QMenu *fileMenu = menubar->addMenu("文件(F)");
    QMenu *editMenu = menubar->addMenu("编辑(E)");
    QMenu *formateMenu = menubar->addMenu("格式(O)");
    QMenu *viewMenu = menubar->addMenu("查看(V)");
    QMenu *helpMenu = menubar->addMenu("帮助(H)");
    //1.2、创建菜单项
    QAction *newAction = fileMenu->addAction("新建");
    fileMenu->addSeparator();//添加分隔符
    QAction *newOpen = fileMenu->addAction("打开");

    //2、创建工具栏，可以有多个(add...)
    QToolBar *toolbar = new QToolBar(this);
    addToolBar(Qt::TopToolBarArea, toolbar);//放入到窗口中并停靠在顶部
    toolbar->setAllowedAreas(Qt::AllToolBarAreas);//设置允许的停靠范围
    toolbar->setFloatable(false);//设置浮动状态
    //2.1、添加工具项
    toolbar->addAction(newAction);
    toolbar->addAction(newOpen);
    //2.2、添加按钮控件
    QPushButton *btn = new QPushButton("工具栏", this);
    toolbar->addWidget(btn);

    //3、创建状态栏，可以有多个(add...)
    QStatusBar *stabar = new QStatusBar(this);
    setStatusBar(stabar);//放入窗体中
    //3.1、添加标签控件
    QLabel *label = new QLabel("提示信息",this);
    label->Box;
    //stabar->addWidget(label);//默认在左侧
    stabar->addPermanentWidget(label);//创建在右侧

    //4、创建铆接部件（浮动窗口），可以有多个(add...)
    QDockWidget *dockeidget = new QDockWidget("浮动",this);
    addDockWidget(Qt::BottomDockWidgetArea, dockeidget);//添加到窗口中
    dockeidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);//设置停靠位置

    //5、创建中心部件,只能有一个(set...)
    QTextEdit *edit = new QTextEdit(this);
    setCentralWidget(edit);//放入窗口中
}

MainWindow::~MainWindow()
{

}
