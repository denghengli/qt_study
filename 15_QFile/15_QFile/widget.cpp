#include "widget.h"
#include "ui_widget.h"
#include "QFileDialog"
#include "QFile"
#include "QFileInfo"
#include "QDebug"
#include "QDateTime"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击选取文件按钮，弹出文件对话框
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QString path = QFileDialog::getOpenFileName(this, "打开文件", "H:\C++\QTProject\15_QFile");
        ui->lineEdit->setText(path);//将路径显示在lineEdit中
        //读取内容放到textEdit中
        QFile file(path);
        file.open(QIODevice::ReadOnly);
        QByteArray array;
        //array = file.readAll();//全部读取
        while (!file.atEnd())
        {
            array += file.readLine();//按行读取追加到文件末尾
        }
        //将读取到的数据放入textEdit中,QFile默认支持的个数是utf-8
        ui->textEdit->setText(array);
        file.close();

        //获取文件信息
        QFileInfo info(path);
        qDebug() <<" 大小:" <<info.size() \
                 <<" 后缀名:" <<info.suffix() \
                 <<" 文件名称:" <<info.fileName().toUtf8().data()\
                 <<" 文件路径:" <<info.path();
        qDebug() <<" 创建日期:" <<info.created().toString("yyyy/MM/dd hh:mm:ss");
        qDebug() <<" 修改日期:" <<info.lastModified().toString("yyyy/MM/dd hh:mm:ss");

        //开始写
        file.open(QIODevice::Append);//追加方式写入
        file.write("练习123");
        file.close();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{

}
