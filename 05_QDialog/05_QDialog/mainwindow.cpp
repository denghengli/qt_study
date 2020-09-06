#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDialog"
#include "QDebug"
#include "QMessageBox"
#include "QColorDialog"
#include "QFileDialog"
#include "QFontDialog"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionNew->setIcon(QIcon(":/image/1.png"));
    ui->actionOpen->setIcon(QIcon(":/image/2.png"));
    ui->actionClose->setIcon(QIcon(":/image/3.png"));

    //1、自定义对话框
    //对话框：模态对话框(不可以对其他窗口进行操作) 非模态对话框(可以对其他窗口进行操作)
    connect(ui->actionNew, &QAction::triggered, [=](){
        //1.1、模态对话框创建,有阻塞的功能
//        QDialog *dlg1 = new QDialog(this);
//        dlg1->resize(200,200);
//        dlg1->exec();

        //1.2、非模态对话框创建,
        QDialog *dlg2 = new QDialog(this);//避免一闪而过,创建在堆区
        dlg2->resize(250,250);
        dlg2->show();
        dlg2->setAttribute(Qt::WA_DeleteOnClose);//防止过度创建导致内存泄露,设置属性(55) 在关闭时删除
    });

    //2、消息对话框
    connect(ui->actionOpen, &QAction::triggered, [=](){
        //QMessageBox::critical(this, "提示", "错误消息对话框");

        //QMessageBox::information(this, "提示", "信息消息对话框");

        //QMessageBox::warning(this, "提示", "警告消息对话框");

        //参数: 父亲 标题 提示内容 按键类型 默认关联回车按键
        //返回值：enum QMessageBox::StandardButton
        //QMessageBox::question(this, "提示", "提问消息对话框");
        if (QMessageBox::Save == QMessageBox::question(this, "提示", "提问消息对话框", QMessageBox::Save|QMessageBox::Cancel, QMessageBox::Cancel))
        {
            qDebug() <<"选择的是保存";
        }
        else
        {
            qDebug() <<"选择的是取消";
        }
    });

    //3、颜色对话框
    connect(ui->actionClose, &QAction::triggered, [=](){
        QColor color = QColorDialog::getColor(QColor(255,0,0));
        qDebug() <<"r=" <<color.red() <<" g=" <<color.green() <<" b=" <<color.black();
    });

    //4、文件对话框
    connect(ui->actionfile, &QAction::triggered, [=](){
        QString str = QFileDialog::getExistingDirectory(this);
        //QFileDialog::getOpenFileNames(this, )
        qDebug() <<"dir : " <<str;
    });

    //5、字体对话框
    connect(ui->actionfont, &QAction::triggered, [=](){
        bool flag;
        QFont font = QFontDialog::getFont(&flag, QFont("华文彩云",10),this);
        if (flag){
            qDebug() <<"字体:" <<font.family().toUtf8().data() <<" 字号" <<font.pointSize();
            qDebug() <<"font is set to the font the user selected";
        } else {
            qDebug() <<"the user canceled the dialog; font is set to the initial";
        }
        //qDebug() <<"font : " <<font.Style;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
