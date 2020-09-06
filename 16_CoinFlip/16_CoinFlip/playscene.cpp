#include "playscene.h"
#include "QMenuBar"
#include "QPainter"
#include "QPixmap"
#include "QDebug"
#include "mypushbutton.h"
#include "QTimer"
#include "QLabel"
#include "mycoin.h"
#include "dataconfig.h"
#include <QPropertyAnimation>
#include <QSound>

//PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
//{

//}


PlayScene::PlayScene(int levelNum)
{
    QString str = QString("进入了第 %1 关").arg(levelNum);
    qDebug() <<str.toUtf8().data();
    this->levelIndex = levelNum;

    //初始化游戏场景
    this->setFixedSize(320,588);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("翻金币场景");

    //创建菜单栏
    QMenuBar *bar = menuBar();
    setMenuBar(bar);
    QMenu *startMenu = bar->addMenu("开始");//创建开始菜单
    QAction *quitAction = startMenu->addAction("退出"); //场景退出的菜单项
    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });

    //胜利的音效
    QSound *winsound = new QSound(":/res/LevelWinSound.wav", this);
    //翻金币音效
    QSound *flipsound = new QSound(":/res/ConFlipSound.wav", this);
    //返回音效
    QSound *backsound = new QSound(":/res/BackButtonSound.wav", this);


    //创建返回按钮
    MyPushbutton *backbtn = new MyPushbutton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backbtn->setParent(this);
    backbtn->move(this->width()-backbtn->width(), this->height()-backbtn->height());
    //点击之后返回选择场景
    connect(backbtn, &MyPushbutton::clicked, [=](){
        //播放返回音效
        backsound->play();

        qDebug() <<"翻金币场景点击了返回按钮";
        //需要告诉选择场景,翻金币场景返回了,选择d场景监听 chooseScene 的返回
        QTimer::singleShot(10, this, [=](){
            emit this->chooseSceneBack();//延时返回
        });
    });

    //创建显示关卡的文本
    QLabel *label = new QLabel;
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    QString str1 = QString("Level: %1").arg(this->levelIndex);
    label->setParent(this);
    label->setFont(font);
    label->setText(str1);
    label->setGeometry(30, this->height()-50, 130, 50);

    //初始化每个关卡的二维数组,记录金币的正反面状态
    dataconfig config;
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            this->gameArray[i][j] = config.mData[this->levelIndex][i][j];
        }
    }

    //胜利图片显示
    QLabel *winLabel = new QLabel;
    QPixmap tmppix;
    tmppix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0,0,tmppix.width(),tmppix.height());
    winLabel->setPixmap(tmppix);
    winLabel->setParent(this);
    winLabel->move((this->width()-tmppix.width())*0.5, -tmppix.height());

    //显示金币
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            //显示金币的背景图片
            QPixmap pix = QPixmap(":/res/BoardNode.png");
            QLabel *label = new QLabel;
            label->setGeometry(0,0,pix.width(),pix.height());
            label->setPixmap(pix);
            label->setParent(this);
            label->move(40+i*60, 200+j*60);

            //创建金币
            QString str;
            if (this->gameArray[i][j] == 1){
                str = ":/res/Coin0001.png";
            } else {
                str = ":/res/Coin0008.png";
            }
            MyCoin *coin = new MyCoin(str);
            coin->setParent(this);
            coin->move(44+i*60, 205+j*60);

            //给金币的属性赋值
            coin->posX = i;//记录X坐标
            coin->posY = j;//记录y坐标
            coin->flag = gameArray[i][j];//记录正反标志 1正面 0反面

            //记录金币的句柄,以便后期的维护
            this->coinbtns[i][j] = coin;

            //监听金币按钮的点击事件,进行翻转
            connect(coin, &MyCoin::clicked, [=](){
                //播放翻金币音效
                flipsound->play();

                //点击金币后,在翻金币前,先禁用其他金币的点击响应,否则手速快会出现bug
                for (int i=0; i<4; i++)
                {
                    for (int j=0; j<4; j++)
                    {
                        this->coinbtns[i][j]->isWin = true;
                    }
                }

                //翻转点击的金币
                coin->changeFlag();
                this->gameArray[coin->posX][coin->posY] = (this->gameArray[coin->posX][coin->posY] == 0)?1:0;

                //延时 翻转周围金币
                QTimer::singleShot(300, this, [=](){
                    if (coin->posX+1 <= 3)//翻转右侧金币
                    {
                        this->coinbtns[coin->posX+1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX+1][coin->posY] = (this->gameArray[coin->posX+1][coin->posY] == 0)?1:0;
                    }
                    if (coin->posX-1 >= 0)//翻转左侧金币
                    {
                        this->coinbtns[coin->posX-1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX-1][coin->posY] = (this->gameArray[coin->posX-1][coin->posY] == 0)?1:0;
                    }
                    if (coin->posY-1 >= 0)//翻转上侧金币
                    {
                        this->coinbtns[coin->posX][coin->posY-1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY-1] = (this->gameArray[coin->posX][coin->posY-1] == 0)?1:0;
                    }
                    if (coin->posY+1 <= 3)//翻转下侧金币
                    {
                        this->coinbtns[coin->posX][coin->posY+1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY+1] = (this->gameArray[coin->posX][coin->posY+1] == 0)?1:0;
                    }

                    //翻转完所有金币后,才启用其他金币的点击响应,否则手速快会出现bug
                    for (int i=0; i<4; i++)
                    {
                        for (int j=0; j<4; j++)
                        {
                            this->coinbtns[i][j]->isWin = false;
                        }
                    }

                    //判断是否胜利
                    this->isWin = true;
                    for (int i=0; i<4; i++)
                    {
                        for (int j=0; j<4; j++)
                        {
                            if (this->gameArray[i][j] == false)
                            {
                                this->isWin = false;
                                break;
                            }
                        }
                    }
                    if (this->isWin == true)
                    {
                        //播放胜利音效
                        winsound->play();

                        qDebug() <<"游戏胜利";

                        //将胜利的图片降下来
                        QPropertyAnimation *animation = new QPropertyAnimation(winLabel, "geometry");
                        //设置动画时间间隔
                        animation->setDuration(1000);
                        //起始位置
                        animation->setStartValue(QRect(winLabel->x(), winLabel->y(), winLabel->width(), winLabel->height()));
                        //结束位置
                        animation->setEndValue(QRect(winLabel->x(), winLabel->y()+110, winLabel->width(), winLabel->height()));
                        //设置缓和曲线
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        //执行动画
                        animation->start();

                        //胜利后 将每个btn的标志都改为true,再点击按钮,不做响应
                        for (int i=0; i<4; i++)
                        {
                            for (int j=0; j<4; j++)
                            {
                                this->coinbtns[i][j]->isWin = true;
                            }
                        }
                    }

                });
            });
        }
    }
}


void PlayScene::paintEvent(QPaintEvent *)
{
    QPixmap pix;
    QPainter painter(this);

    //加载背景
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.5, pix.height()*0.5);//对图片进行缩放
    painter.drawPixmap(10,30,pix);
}

















