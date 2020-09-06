#include "smallwidget.h"
#include "ui_smallwidget.h"

smallWidget::smallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::smallWidget)
{
    ui->setupUi(this);

    //QSpinBox移动 QSlider跟着移动,反之亦可以
    void (QSpinBox::*spinsingal)(int) = &QSpinBox::valueChanged;//信号发生了重载,需要用函数指针指明需要使用的信号
    connect(ui->spinBox, spinsingal, ui->horizontalSlider, &QSlider::setValue);

    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
}

smallWidget::~smallWidget()
{
    delete ui;
}

//自己添加的成员函数
void smallWidget::setNum(int num)
{
    ui->spinBox->setValue(num);
}

int smallWidget::getNum()
{
    return ui->spinBox->value();
}
