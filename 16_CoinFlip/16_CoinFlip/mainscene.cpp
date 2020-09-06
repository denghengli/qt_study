#include "mainscene.h"
#include "ui_mainscene.h"
#include "QPainter"
#include "QPixmap"
#include "mypushbutton.h"
#include "QDebug"
#include "chooselevelscene.h"
#include "QTimer"
#include "QSound"//多媒体模块下的音效头文件

mainscene::mainscene(QWidget *parent) : QMainWindow(parent), ui(new Ui::mainscene)
{
    ui->setupUi(this);

    //配置主场景
    setFixedSize(320,588);//设置固定大小
    setWindowIcon(QIcon(":/res/Coin0001.png"));//设置图标
    setWindowTitle("翻金币主场景");//设置标题

    //菜单栏-->退出选项 的实现
    connect(ui->actionQuit, &QAction::triggered, [=](){
        this->close();
    });

    //准备开始按钮的音效
    QSound *startsound = new QSound(":/res/TapButtonSound.wav", this);

    //实例化选择关卡场景
    chooseScene = new ChooseLevelScene;
    //监听选择关卡的返回按钮信号
    connect(chooseScene, &ChooseLevelScene::chooseSceneBack, this, [=](){
        chooseScene->hide();//隐藏选择关卡
        this->setGeometry(chooseScene->geometry());//由选择场景返回时,设置主场景的位置,不然会乱动
        this->show();//重新显示主场景
    });

    //开始按钮,使用自定义的PushButton
    MyPushbutton *startbtn = new MyPushbutton(":/res/MenuSceneStartButton.png");
    startbtn->setParent(this);
    startbtn->move(this->width()*0.5 - startbtn->width()*0.5, this->height()*0.7);
    connect(startbtn, &MyPushbutton::clicked, [=](){
        qDebug() <<"点击了开始";
        startbtn->zoom1();
        startbtn->zoom2();

        //播放音效
        startsound->play();
        //startsound->setLoops(-1);//设置循环,如果是-1表示无限循环

        //延时进入选择关卡，才能看见弹跳的效果
        QTimer::singleShot(100,this,[=](){
            this->hide();//隐藏主场景
            chooseScene->setGeometry(this->geometry());//进入选择场景时,设置选择场景的位置,不然会乱动
            chooseScene->show();//显示选择关卡的场景
        });
    });
}

mainscene::~mainscene()
{
    delete ui;
}

//重写paintEvent事件，画背景图
void mainscene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;

    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(), this->height(), pix);

    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.5, pix.height()*0.5);//对图片进行缩放
    painter.drawPixmap(10,30,pix);
}




















