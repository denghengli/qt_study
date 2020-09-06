#include "chooselevelscene.h"
#include "QMenuBar"
#include "QPainter"
#include "QPixmap"
#include "QDebug"
#include "mypushbutton.h"
#include "QTimer"
#include "QLabel"
#include "QSound"

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    //配置选择关卡场景
    this->setFixedSize(320,588);
    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("选择关卡场景");

    //创建菜单栏
    QMenuBar *bar = menuBar();
    setMenuBar(bar);
    QMenu *startMenu = bar->addMenu("开始");//创建开始菜单项
    QAction *quitAction = startMenu->addAction("退出"); //场景退出的菜单项
    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });

    //选择关卡音效
    QSound *choosesound = new QSound(":/res/TapButtonSound.wav", this);
    //返回音效
    QSound *backsound = new QSound(":/res/BackButtonSound.wav", this);

    //创建返回按钮
    MyPushbutton *backbtn = new MyPushbutton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backbtn->setParent(this);
    backbtn->move(this->width()-backbtn->width(), this->height()-backbtn->height());
    //点击之后返回主场景
    connect(backbtn, &MyPushbutton::clicked, [=](){
        //播放返回音效
        backsound->play();

        qDebug() <<"选择场景点击了返回按钮";
        //需要告诉主场景,选择场景返回了,主场景监听 chooseScene 的返回
        QTimer::singleShot(100, this, [=](){
            emit this->chooseSceneBack();//延时返回
        });
    });

    //场景选择按钮
    for (int i=0; i<20; i++)
    {
        //创建按钮
        MyPushbutton *menuBtn = new MyPushbutton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25+i%4*70, 130+i/4*70);

        //创建按钮文本
        QLabel *label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        label->setText(QString::number(i+1));
        label->move(25+i%4*70, 130+i/4*70);
        label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter); //设置文字对齐方式
        label->setAttribute(Qt::WA_TransparentForMouseEvents); //设置让鼠标进行穿透!!!!这样menuBtn才能收到点击事件

        //监听每个按钮的点击事件
        connect(menuBtn, &MyPushbutton::clicked, [=](){
            //播放音效
            choosesound->play();

            QString str = QString("选择的关卡是 %1 关").arg(i+1);
            qDebug() <<str.toUtf8().data();

            //进入到游戏场景
            this->hide();//隐藏选择场景
            this->play = new PlayScene(i+1);
            this->play->setGeometry(this->geometry());//进入翻金币场景时,设置其位置
            this->play->show();//进入游戏场景

            //监听游戏场景的返回信号
            connect(play, &PlayScene::chooseSceneBack, [=](){
                this->setGeometry(this->play->geometry());//翻金币场景返回时,设置选择场景的位置
                this->show();//展示选择场景,这里不会立马显示出来????????
                delete this->play;//删除翻金币场景
                this->play = NULL;
            });
        });
    }
}

//重写绘图事件,绘制背景
void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;

    //加载背景
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/res/Title.png");
    //pix = pix.scaled(pix.width()*0.5, pix.height()*0.5);//对图片进行缩放
    painter.drawPixmap(10,30,pix);
}


















