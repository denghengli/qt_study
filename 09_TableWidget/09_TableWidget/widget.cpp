#include "widget.h"
#include "ui_widget.h"
#include "QStringList"
#include "QTableWidget"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //TableWidget
    ui->tableWidget->setColumnCount(3);//设置列数
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() <<"姓名" <<"性别" <<"年龄");//设置水平表头

    ui->tableWidget->setRowCount(5);//设置行数
    QStringList namelist, sexlist;
    namelist <<"亚瑟" <<"赵云" <<"张飞" <<"关羽" <<"花木兰";
    sexlist <<"男" <<"男" <<"男" <<"男" <<"女";
    QTableWidgetItem* item[5][3];
    for (int i=0; i<5; i++)//行数
    {
        int col = 0;//列数
        item[i][0] = new QTableWidgetItem(namelist[i]);//创建一个item
        item[i][0]->setIcon(QIcon(":/image/1.png"));//设置背景
        item[i][0]->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//设置对齐方式
        ui->tableWidget->setItem(i,col++, item[i][0]);//添加项目

        item[i][1] = new QTableWidgetItem(sexlist[i]);
        item[i][1]->setIcon(QIcon(":/image/2.png"));
        item[i][1]->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidget->setItem(i,col++, item[i][1]);

        item[i][2] = new QTableWidgetItem(QString::number(i+18));
        item[i][2]->setIcon(QIcon(":/image/3.png"));
        item[i][2]->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidget->setItem(i,col++, item[i][2]);
    }
}

Widget::~Widget()
{
    delete ui;
}































