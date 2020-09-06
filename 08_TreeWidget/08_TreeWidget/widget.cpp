#include "widget.h"
#include "ui_widget.h"
#include "QStringList"
#include "QString"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //1、TreeWidget树控件使用
    //设置水平头
    ui->treeWidget->setHeaderLabels(QStringList() <<"英雄" <<"英雄简介");
    QTreeWidgetItem *liitem = new QTreeWidgetItem(QStringList() <<"力量");
    QTreeWidgetItem *minjieitem = new QTreeWidgetItem(QStringList() <<"敏捷");
    QTreeWidgetItem *zhiliitem = new QTreeWidgetItem(QStringList() <<"智力");
    //加载顶层的节点
    ui->treeWidget->addTopLevelItem(liitem);
    ui->treeWidget->addTopLevelItem(minjieitem);
    ui->treeWidget->addTopLevelItem(zhiliitem);
    //追加子节点
    QTreeWidgetItem *li1 = new QTreeWidgetItem(QStringList() <<"fdsafgd" <<"范德萨山东高考来了发的桑");
    QTreeWidgetItem *li2 = new QTreeWidgetItem(QStringList() <<"fdsafgd" <<"范德萨山东高考来了发的桑");
    QTreeWidgetItem *li3 = new QTreeWidgetItem(QStringList() <<"fdsafgd" <<"范德萨山东高考来了发的桑");
    liitem->addChild(li1);liitem->addChild(li2);liitem->addChild(li3);

    QTreeWidgetItem *mj1 = new QTreeWidgetItem(QStringList() <<"fdsafgd" <<"范德萨山东高考来了发的桑");
    QTreeWidgetItem *mj2 = new QTreeWidgetItem(QStringList() <<"fdsafgd" <<"范德萨山东高考来了发的桑");
    QTreeWidgetItem *mj3 = new QTreeWidgetItem(QStringList() <<"fdsafgd" <<"范德萨山东高考来了发的桑");
    minjieitem->addChild(mj1);minjieitem->addChild(mj2);minjieitem->addChild(mj3);

    QTreeWidgetItem *zl1 = new QTreeWidgetItem(QStringList() <<"fdsafgd" <<"范德萨山东高考来了发的桑");
    QTreeWidgetItem *zl2 = new QTreeWidgetItem(QStringList() <<"fdsafgd" <<"范德萨山东高考来了发的桑");
    QTreeWidgetItem *zl3 = new QTreeWidgetItem(QStringList() <<"fdsafgd" <<"范德萨山东高考来了发的桑");
    zhiliitem->addChild(zl1);zhiliitem->addChild(zl2);zhiliitem->addChild(zl3);
}

Widget::~Widget()
{
    delete ui;
}



























