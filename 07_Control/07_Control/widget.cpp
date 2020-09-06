#include "widget.h"
#include "ui_widget.h"
#include "QDebug"
#include "QListWidget"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //1、单选按钮，设置默认选中
    ui->radioBtn_man->setChecked(true);

    connect(ui->radioBtn_woman, &QRadioButton::clicked, [=](){
        qDebug() <<"女单选钮按下";
    });

    //2、多选按钮，获取选中状态2是选中 0是未选中
    connect(ui->checkBox_serv, &QCheckBox::stateChanged, [=](int state){
        qDebug() <<state;
    });

    //3、listWidget列表，插入item
    QListWidgetItem *item = new QListWidgetItem("锄禾日当午");
    item->setTextAlignment(Qt::AlignHCenter|Qt::AlignCenter);
    ui->listWidget->addItem(item);//单个添加

    QStringList items;
    items <<"锄禾日当午" <<"汗滴禾下土" <<"谁知盘中餐" <<"粒粒皆辛苦";
    ui->listWidget->addItems(items);//多个添加
}

Widget::~Widget()
{
    delete ui;
}
