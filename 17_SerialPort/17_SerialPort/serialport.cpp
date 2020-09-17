#include "serialport.h"
#include "ui_serialport.h"
#include <QPalette>
#include <QColor>
#include <QStatusBar>
#include <QString>
#include <QDebug>
#include <QList>
#include <QMessageBox>
#include <QByteArray>
#include <QTextCodec>
#include <QFileDialog>
#include <QFileDevice>
#include <QFile>
#include <QTextStream>

SerialPort::SerialPort(QWidget *parent) : QMainWindow(parent), ui(new Ui::SerialPort)
{
    ui->setupUi(this);

    //设置窗口
    //setFixedSize(790,728);//设置固定大小
    setWindowIcon(QIcon(":/res/USB.png"));//设置图标
    setWindowTitle("串口调试助手");//设置标题

    //设置背景颜色
    QPalette *palette = new QPalette();//创建一个调色板
    palette->setColor(QPalette::Background, QColor(100,100,215));
    this->setPalette(*palette);

    //创建状态栏
    initStatusbar();

    //创建串口
    this->port = new QSerialPort(this);

    //初始化配置
    initPort();

    //创建定时发送定时器
    this->delayed_timer = new QTimer(this);
    this->delayed_period = 1000;//默认1000ms
    ui->lineEdit_period->setText(QString("%1").arg(this->delayed_period));

    //创建时间刷新定时器
    this->freshTimer = new QTimer(this);
    this->freshTimer->start(500);
    connect(freshTimer, &QTimer::timeout, [=](){
        curTimeStatus->setText(curTime->currentTime().toString("当前时间 hh:mm:ss"));
    });

    //关联信号和槽函数
    connect(ui->Btn_open,SIGNAL(clicked()),this,SLOT(openbtn_clicked()));
    connect(ui->Btn_save,SIGNAL(clicked()),this,SLOT(savebtn_clicked()));
    connect(ui->Btn_clearrx,SIGNAL(clicked()),this,SLOT(clrrxbtn_clicked()));
    connect(ui->Btn_cleartx,SIGNAL(clicked()),this,SLOT(clrtxbtn_clicked()));
    connect(ui->Btn_send,SIGNAL(clicked()),this,SLOT(sendbtn_clicked()));
    connect(ui->Btn_stopsend,SIGNAL(clicked()),this,SLOT(stopsendbtn_clicked()));
    connect(ui->Btn_openfile,SIGNAL(clicked()),this,SLOT(openfilebtn_clicked()));
    connect(ui->Btn_sendfile,SIGNAL(clicked()),this,SLOT(sendfilebtn_clicked()));
    connect(this->delayed_timer, SIGNAL(timeout()), this, SLOT(serial_write()));
    connect(ui->checkBox_tx_delayed, SIGNAL(stateChanged(int)), this, SLOT(delayedcB_changed()));
    connect(ui->checkBox_tx_hexsend, SIGNAL(stateChanged(int)), this, SLOT(hexsendcB_changed()));
}

SerialPort::~SerialPort()
{
    delete ui;
}

//初始化状态栏
void SerialPort::initStatusbar()
{
    portStatus = new QLabel("串口状态：关闭");
    portStatus->setMinimumSize(200,20);
    portStatus->setAlignment(Qt::AlignHCenter);
    statusBar()->addWidget(portStatus);

    rxStatus = new QLabel(QString("R: %1 bytes").arg(rxBytes));
    rxStatus->setMinimumSize(200,20);
    rxStatus->setAlignment(Qt::AlignHCenter);
    statusBar()->addWidget(rxStatus);

    txStatus = new QLabel(QString("T: %1 bytes").arg(txBytes));
    txStatus->setMinimumSize(200,20);
    txStatus->setAlignment(Qt::AlignHCenter);
    statusBar()->addWidget(txStatus);

    curTimeStatus = new QLabel(curTime->currentTime().toString("当前时间 hh:mm:ss"));
    curTimeStatus->setMinimumSize(200,20);
    curTimeStatus->setAlignment(Qt::AlignHCenter);
    statusBar()->addWidget(curTimeStatus);

    //设置无边框
    statusBar()->setFont(QFont("微软雅黑", 10, QFont::Bold));
    //statusBar()->setStyleSheet(QString("QStatusBar::item{border: 0px}"));
}

//初始化串口
void SerialPort::initPort()
{
    //列出当前系统中可用的串口
    QList<QSerialPortInfo> infos = QSerialPortInfo::availablePorts();
    if(infos.isEmpty())//没有可用的串口
    {
        ui->CB_port->addItem(tr("Empty"));
        return;
    }
    else
    {
        //遍历容器中的所以元素
        foreach (QSerialPortInfo info, infos) {
            ui->CB_port->addItem(info.portName());
        }
    }

    //读取ini的配置信息,保持上一次的配置
    configiniInit();
    configiniRead();

    //接收设置 和 发送设置的默认选择
    ui->checkBox_rx_autoline->setChecked(true);
    ui->checkBox_tx_newline->setChecked(true);
    ui->textEdit_rx->setReadOnly(true);
}

//创建ini配置文件
void SerialPort::configiniInit()
{
    iniPath = new QDir;
    iniFilename = iniPath->currentPath() + "/SerialPort.ini";
    //构造一个QSettings对象，用于访问存储在名为iniFilename的文件中的设置。如果文件不存在，就创建它
    configini = new QSettings(iniFilename, QSettings::IniFormat);
}

//读取ini配置文件,设置下拉框的项目
void SerialPort::configiniRead()
{
    configini->beginGroup("SETUP");
    int i_port = configini->value("COM").toInt();
    int i_baudrate = configini->value("baudrate").toInt();
    int i_databit = configini->value("databit").toInt();
    int i_checkbit = configini->value("checkbit").toInt();
    int i_stopbit = configini->value("stopbit").toInt();
    configini->endGroup();

    ui->CB_port->setCurrentIndex(i_port);
    ui->CB_baudrate->setCurrentIndex(i_baudrate);
    ui->CB_databit->setCurrentIndex(i_databit);
    ui->CB_checkbit->setCurrentIndex(i_checkbit);
    ui->CB_stopbit->setCurrentIndex(i_stopbit);
}

//写ini配置文件,将下拉框的项目索引写入ini文件
void SerialPort::configiniWrite()
{
    configini->beginGroup("SETUP");
    configini->setValue("COM", ui->CB_port->currentIndex());
    configini->setValue("baudrate", ui->CB_baudrate->currentIndex());
    configini->setValue("databit", ui->CB_databit->currentIndex());
    configini->setValue("checkbit", ui->CB_checkbit->currentIndex());
    configini->setValue("stopbit", ui->CB_stopbit->currentIndex());
    configini->endGroup();
}

//获取下拉框配置项文本
void SerialPort::getComboBoxValue()
{
    str_port = ui->CB_port->currentText();
    str_baudrate = ui->CB_baudrate->currentText();
    str_databit = ui->CB_databit->currentText();
    str_checkbit = ui->CB_checkbit->currentText();
    str_stopbit = ui->CB_stopbit->currentText();
}

//串口配置
void SerialPort::portconfig()
{
    port->setPortName(str_port);

    //打开串口 成功
    if (port->open(QIODevice::ReadWrite))
    {
        //设置波特率
        port->setBaudRate(str_baudrate.toInt());
        //设置数据位
        switch(str_databit.toInt())
        {
        case 5:
            port->setDataBits(QSerialPort::Data5); break;

        case 6:
            port->setDataBits(QSerialPort::Data6); break;

        case 7:
            port->setDataBits(QSerialPort::Data7); break;

        case 8:
            port->setDataBits(QSerialPort::Data8); break;

        default:break;
        }
        //设置停止位
        switch(str_stopbit.toInt())
        {
        case 1:
            port->setStopBits(QSerialPort::OneStop); break;

        case 2:
            port->setStopBits(QSerialPort::TwoStop); break;

        default:break;
        }
        //设置校验位
        switch(ui->CB_checkbit->currentIndex())
        {
        case 0:
            port->setParity(QSerialPort::NoParity); break;

        case 1:
            port->setParity(QSerialPort::EvenParity); break;

        case 2:
            port->setParity(QSerialPort::OddParity); break;

        default:break;
        }

        isOpen = true;//打开成功
    }
    //串口打开失败
    else
    {
        isOpen = false;//打开失败
        QMessageBox::warning(this, "错误提示", "串口打开失败!！！");
    }
}

//打开和关闭串口,打开串口时关联readyRead()串口有数据可读信号 和 serial_read()读取串口数据槽函数
void SerialPort::openbtn_clicked()
{
    //打开串口
    if (!isOpen)
    {
        //保存配置信息(下拉框配置项的索引)
        configiniWrite();
        //获取配置信息文本(下拉框配置项的文本)
        getComboBoxValue();
        //配置串口
        portconfig();

        if (isOpen) //串口配置成功
        {
            ui->Btn_open->setText(tr("关闭"));
            ui->Btn_open->setStyleSheet("background-color:rgb(50,250,120);");//设置样式
            //关联数据读取的槽函数
            connect(port, SIGNAL(readyRead()), this, SLOT(serial_read()));
            //更改串口的状态
            portStatus->setText("串口状态：打开");
        }
    }
    else //关闭串口
    {
        isOpen = false;
        savefile_flag = false;
        port->close();
        ui->Btn_open->setText(tr("打开"));
        ui->Btn_open->setStyleSheet("background-color:rgb(225,225,225);");//设置样式
        //更改串口的状态
        portStatus->setText("串口状态：关闭");
    }
}

//保存接收
void SerialPort::savebtn_clicked()
{
    //打开文件另存为窗口
    savefile_path = QFileDialog::getSaveFileName(this,"另存为", savefile_path, "Text File(*.txt)");
    qDebug() <<savefile_path;

    QFile file(savefile_path);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,"打开文件", "文件打开失败");
        return;
    }
    savefile_flag = true;
    file.close();
}

//清空接收文本编辑框
void SerialPort::clrrxbtn_clicked()
{
    rxBytes = 0;
	txBytes = 0;
    ui->textEdit_rx->clear();
    rxStatus->setText(QString("R: %1 bytes").arg(rxBytes));
	txStatus->setText(QString("T: %1 bytes").arg(txBytes));
}

//清空发送文本编辑框
void SerialPort::clrtxbtn_clicked()
{
    txBytes = 0;
    ui->textEdit_tx->clear();
    txStatus->setText(QString("T: %1 bytes").arg(txBytes));
}

//点击发送按钮发送数据
void SerialPort::sendbtn_clicked()
{
    serial_write();
}

void SerialPort::stopsendbtn_clicked()
{

}

void SerialPort::openfilebtn_clicked()
{
    openfile_path = QFileDialog::getOpenFileName(this, "打开文件", "", "Text File(*.txt)");
    ui->lineEdit_file->setText(openfile_path);//将路径显示在lineEdit中
}

void SerialPort::sendfilebtn_clicked()
{
    QFile file(openfile_path);
    if (port->isOpen())
    {
        if(!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this, "打开文件", "文件打开失败");
        }
        else
        {
            QByteArray array;
            array = file.readAll();
            //发送数据
            port->write(array);
            txBytes += array.length();//发送字节数累加
            file.close();
            QMessageBox::information(this, "发送文件", "文件发送成功");
        }
    }
    else
    {
        QMessageBox::warning(this, "错误提示", "请先打开串口");
    }
}

//定时发送checkBox状态改变
void SerialPort::delayedcB_changed()
{
    if(port->isOpen())
    {
        //选择了定时发送
        if(ui->checkBox_tx_delayed->isChecked())
        {
            if(!delayed_timer->isActive())
            {
                delayed_period = ui->lineEdit_period->text().toInt();
                delayed_timer->start(delayed_period);
            }
        }
        //关闭了定时发送
        else
        {
            if(delayed_timer->isActive())
            {
                delayed_timer->stop();
            }
        }
    }
    else
    {
        QMessageBox::warning(this, "错误提示", "请先打开串口");
        ui->checkBox_tx_delayed->setChecked(false);
    }
}

//16进制发送状态改变
void SerialPort::hexsendcB_changed()
{
    QString sendstr = ui->textEdit_tx->toPlainText();//获取发送数据 QString
    if(ui->checkBox_tx_newline->isChecked())//发送新行
        sendstr += "\r\n";

    ui->textEdit_tx->clear();//清空显示区

    //字符 --> GBK编码字符
	//比如:"123学习" --> "31 32 33 D1 A7 CF B0"
    if(ui->checkBox_tx_hexsend->isChecked())
    {
        //"123学习" --> GBK编码：31 32 33 D1 A7 CF B0
        QByteArray sendarray = sendstr.toLocal8Bit();//"123学习"在QT中是UTF8编码的,所以这里需要使用toLocal8Bit转成Winds中的GBK编码
        //GBK编码：31 32 33 D1 A7 CF B0 --> GBK编码字符："31 32 33 D1 A7 CF B0"
        QDataStream out(&sendarray,QIODevice::ReadWrite);    //将字节数组读入
        while(!out.atEnd())
        {
            qint8 outChar = 0;
            out>>outChar;   //每字节填充一次，直到结束
            QString str = QString("%1").arg(outChar&0xFF,2,16,QLatin1Char('0'));
            str = str.toUpper();
            ui->textEdit_tx->insertPlainText(str + " ");//在当前光标处插入文本
            //返回表示当前可见游标的QTextCursor副本。对返回游标的更改不会影响QTextEdit的游标;使用setTextCursor()更新可见的游标
            QTextCursor cursor = ui->textEdit_tx->textCursor();
            cursor.movePosition(QTextCursor::End);//将光标移动到文档的最后
            ui->textEdit_tx->setTextCursor(cursor);//更新光标
        }
    }
    //GBK编码字符 --> 字符
	//比如:"31 32 33 D1 A7 CF B0" --> "123学习"
    else
    {
        QByteArray sendarray;
        //GBK编码字符:"31 32 33 D1 A7 CF B0" --> GBK编码:31 32 33 D1 A7 CF B0
        QStringtoHex(sendarray, sendstr);
        //GBK编码:31 32 33 D1 A7 CF B0 --> Unicode编码 --> "123学习"
        QString str1 = QString::fromLocal8Bit(sendarray);//实现了从本地字符集GBK到Unicode的转换,解决中文显示乱码问题
        ui->textEdit_tx->setText(str1);
    }
}

//从串口读取数据显示在显示区
//从串口读取到的都是QByteArray字符格式的GBK编码
//windowns中的字符都是GBK编码,而在QT中默认编码是UTF-8,所以需要使用fromLocal8Bit将GBK编码转成UTF-8编码
void SerialPort::serial_read()
{
    //显示当前时间
    if (ui->checkBox_rx_disptime->isChecked())
    {
        QString timestr = curTime->currentTime().toString("[hh:mm:ss.zzz]");
        display_message(timestr);
    }

    ////GBK编码：31 32 33 D1 A7 CF B0 --> GBK编码字符："31 32 33 D1 A7 CF B0"
    if (ui->checkBox_rx_hexdisp->isChecked())
    {
        QByteArray data = port->readAll();
        QDataStream out(&data,QIODevice::ReadWrite);    //将字节数组读入
        while(!out.atEnd())
        {
            qint8 outChar = 0;
            out>>outChar;   //每字节填充一次，直到结束
            QString str = QString("%1").arg(outChar&0xFF,2,16,QLatin1Char('0'));
            str = str.toUpper();

            display_message(str + " ");
        }
        rxBytes += data.length();//累加获取的数据字节数
    }
    //GBK编码：31 32 33 D1 A7 CF B0 --> 字符："123学习"
    else
    {
        QByteArray data = port->readAll();
        QString str = QString::fromLocal8Bit(data);//实现了从本地字符集GBK到Unicode的转换,解决中文显示乱码问题
        display_message(str);
        rxBytes += str.length();//累加获取的数据字节数
    }

    //显示换行
    if (ui->checkBox_rx_autoline->isChecked())
    {
        display_message("\r\n");
    }

    //显示接收的字节数
    rxStatus->setText(QString("R: %1 bytes").arg(rxBytes));
}

char SerialPort::ConvertHexChar(char c)
{
    if(c>='a'&&c<='f')
    {
        return c-'a'+10;
    }
    else if(c>='A'&&c<='F')
    {
        return c-'A'+10;
    }
    else if(c>='0'&&c<='9')
    {
        return c-'0';
    }
    else{
        return -1;
    }
}
//"31 32 33 D1 A7 CF B0" --> 31 32 33 D1 A7 CF B0
void SerialPort::QStringtoHex(QByteArray& sendData,QString str)
{
    char hstr,lstr,hdata,ldata;
    int len = str.length();
    int sendnum = 0;
    QByteArray temp;
    temp.resize(len/2);//设置大小，len/2会大于实际16进制字符
    
    for(int i=0;i<len;)
    {
        hstr = str[i].toLatin1();
        if(hstr == ' ')
        {
            ++i;
            continue;
        }
        ++i;
        if(i >= len)
        {
            break;
        }
        lstr = str[i].toLatin1();

        hdata = ConvertHexChar(hstr);
        ldata = ConvertHexChar(lstr);
        if(-1 == hdata || -1 == ldata)
        {
            break;
        }
        ++i;
        temp[sendnum] = hdata<<4|ldata;
        sendnum++;
    }
    sendData.reserve(sendnum);//重新调整大小
    sendData = temp.left(sendnum);//返回一个 字节数组，其中包含这个字节数组最左边的len字节。去掉多余字符
}

//从串口发送数据,周期发送或点击发送按钮发送
//发送数据类型都是QByteArray字符类的GBK编码
void SerialPort::serial_write()
{
    if(port->isOpen())
    {
        //获取发送数据 QString
        QString sendstr = ui->textEdit_tx->toPlainText();
        //发送新行
        if(ui->checkBox_tx_newline->isChecked())
        {
            sendstr += "\r\n";
        }

        //GBK编码字符:"31 32 33 D1 A7 CF B0" --> GBK编码:31 32 33 D1 A7 CF B0
        if(ui->checkBox_tx_hexsend->isChecked())
        {
            QByteArray sendarray;
            QStringtoHex(sendarray, sendstr);
            port->write(sendarray);
            txBytes += sendarray.length();
        }
        else //字符:"123学习" --> GBK编码:31 32 33 D1 A7 CF B0
        {
            QByteArray sendarray = sendstr.toLocal8Bit();//"123学习"在QT中是UTF8编码的,所以这里需要使用toLocal8Bit转成Winds中的GBK编码
            port->write(sendarray);
            txBytes += sendarray.length();//发送字节数累加

//            //Unicode转GBK 参考博客问答http://bbs.csdn.net/topics/390024555
//            QTextCodec * codec = QTextCodec::codecForName("GBK"); //建立一个unicode与GBK之间的转换器
//            //将sendstr从Unicode转换为该编码器的编码(GBK)，并以QByteArray的形式返回结果。
//            QByteArray bytesForGBK = codec->fromUnicode(sendstr); //unicode转换成gbk
//            //发送数据
//            port->write(bytesForGBK);
//            txBytes += bytesForGBK.length();//发送字节数累加
        }

        //在显示区显示发送数据
        if(ui->checkBox_rx_dispsend->isChecked())
        {
            //显示当前时间
            if (ui->checkBox_rx_disptime->isChecked())
            {
                QString timestr = curTime->currentTime().toString("[hh:mm:ss.zzz]");
                display_message(timestr);
            }
            display_message("send data:");
            display_message(sendstr);
            display_message("\r\n");
        }
    }
    else
    {
        delayed_timer->stop();
        QMessageBox::warning(this, "错误提示", "请先打开串口");
        ui->checkBox_tx_delayed->setChecked(false);
    }

    //显示发送的字节数
    txStatus->setText(QString("T: %1 bytes").arg(txBytes));
}

//在接收区显示数据(从串口读取的和发送的)
void SerialPort::display_message(QString str)
{
    //将显示的内容另存为
    if (savefile_flag)
    {
        QFile file(savefile_path);
        if(file.open(QIODevice::WriteOnly | QIODevice::Append))//追加方式写入
        {
            QTextStream textStream(&file);
            textStream <<str;
            file.close();
        }
    }

    //在当前光标处插入文本
    ui->textEdit_rx->insertPlainText(str);
    //返回表示当前可见游标的QTextCursor副本。
    //注意，对返回游标的更改不会影响QTextEdit的游标;使用setTextCursor()更新可见的游标
    QTextCursor cursor = ui->textEdit_rx->textCursor();
    //将光标移动到文档的最后
    cursor.movePosition(QTextCursor::End);
    //更新光标
    ui->textEdit_rx->setTextCursor(cursor);
}









