/*************************************************************
 * 程序用途：QT串口调试助手
 *
 * 作者：陶聪
 *
 * 联系方式：QQ 1196102361
 * 欢迎大神指点
 * ***********************************************************/
#include "qtportdebug.h"
#include "ui_qtportdebug.h"
#include <QThread>

QTPortDebug::QTPortDebug(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QTPortDebug)
{
    //设置背景颜色
    setground();

    ui->setupUi(this);

    SPort = new QSerialPort(this);

    iniPort();

    //新建定时器
    timer=new QTimer(this);
    time_cycle = 1000;

    //定时器超时运行发送函数
    connect(timer,SIGNAL(timeout()),this,SLOT(sendupdata()));
    this->connect(ui->check_repsend,SIGNAL(stateChanged(int)), this,SLOT(CheckAutoRun()));
    this->connect(ui->cb_record, SIGNAL(activated(int)), this, SLOT(fillrecord()));

    //接受和发送的字节数
    rxbyte = 0;
    txbyte = 0;

    DisplayTimeStatus = false;

    initStatusbar();

    runonce = true;

    this->setWindowTitle(tr("SerialDebuging"));
}

QTPortDebug::~QTPortDebug()
{
    delete ui;
    if(timer->isActive())
    {
        timer->stop();

    }
    delete timer;
    delete SPort;

    delete rx;
    delete tx;
    delete byterx;
    delete bytetx;
    delete txnum;
    delete rxnum;

}

void QTPortDebug::setcurrentPath()
{
    currentPath = new QDir;
    PATH = currentPath->currentPath() + "/SerialPort.ini";
}
//初始化
void QTPortDebug::iniPort()
{

    QList<QSerialPortInfo>  infos = QSerialPortInfo::availablePorts();
    if(infos.isEmpty())
    {
        ui->CB_port->addItem(tr("Empty"));
        return;
    }
    foreach (QSerialPortInfo info, infos) {
        ui->CB_port->addItem(info.portName());
        //SPort->close();
    }
    //ini配置文件
    config();
    configiniRead();
    //默认选中
    ui->radio_accept_ascii->setChecked(true);
    ui->radio_send_ascii->setChecked(true);
    ui->check_auto_line->setChecked(true);
    //ui->check_repsend->setChecked(true);
    //设置只读
    ui->text_accept->setReadOnly(true);
}

void QTPortDebug::getComboBoxValue()
{
    m_port = ui->CB_port->currentText();
    m_baudrate = ui->CB_baudrate->currentText();
    m_databit = ui->CB_databit->currentText();
    m_check = ui->CB_check->currentText();
    m_stopbit = ui->CB_stopbit->currentText();
//    Com->m_FlowControl  = ui->CB_flow->currentText();

}
//设置串口参数
void QTPortDebug::setPortConfig()
{


    //设置串口号
    SPort->setPortName(m_port);
    if(SPort->open(QIODevice::ReadWrite))
    {
        //设置波特率
        SPort->setBaudRate(m_baudrate.toInt());
        //设置数据位
        switch(m_databit.toInt())
        {
            case 5:
                 SPort->setDataBits(QSerialPort::Data5);break;
            case 6:
                 SPort->setDataBits(QSerialPort::Data6);break;
            case 7:
                 SPort->setDataBits(QSerialPort::Data7);break;
            case 8:
                 SPort->setDataBits(QSerialPort::Data8);break;
            default: break;
        }
        //设置校验位
        switch(ui->CB_check->currentIndex())
        {
            case 0:
                SPort->setParity(QSerialPort::NoParity);break;
            case 1:
                SPort->setParity(QSerialPort::EvenParity);break;
            case 2:
                SPort->setParity(QSerialPort::OddParity);break;
            case 3:
                SPort->setParity(QSerialPort::SpaceParity);break;
            case 4:
                SPort->setParity(QSerialPort::MarkParity);break;
            default: break;
        }
        //设置流控制
        switch(ui->CB_flow->currentIndex())
        {
            case 0:
                SPort->setFlowControl(QSerialPort::NoFlowControl);
            case 1:
                SPort->setFlowControl(QSerialPort::HardwareControl);
            case 2:
                SPort->setFlowControl(QSerialPort::SoftwareControl);
            default: break;
        }

        //设置停止位
        switch(m_stopbit.toInt())
        {
            case 1:
                SPort->setStopBits(QSerialPort::OneStop);
            case 2:
                SPort->setStopBits(QSerialPort::TwoStop);
            default: break;
        }

        //message("config 成功\r\n");
    }
    else{
        QMessageBox::warning(this,tr("warning"),tr("initialization config failed!"));
       // message("config 失败\r\n");
    }


}
//从串口读取数据
void QTPortDebug::SerialRead()
{

    //接受ASCII码字符
    if(ui->radio_accept_ascii->isChecked())
    {

        QByteArray  data = SPort->readAll();
        //实现了从本地字符集GBK到Unicode的转换
        QString str = QString::fromLocal8Bit(data);
        if(DisplayTimeStatus)
        {
            message(currenttime->currentTime().toString("[hh:mm:ss.zzz]"));
        }
        ui->text_accept->insertPlainText(str);

        rxbyte += str.length();//接收数据累加
    }
    //接受16进制字符
    else if( ui->radio_accept_hex->isChecked())
    {
        if(DisplayTimeStatus)
        {
            message(currenttime->currentTime().toString("[hh:mm:ss.zzz]"));
        }
        QByteArray byteArray = SPort->readAll();
        //显示16进制
        //方法一 参考博客http://www.qtcn.org/bbs/read-htm-tid-44071.html
        QDataStream out(&byteArray,QIODevice::ReadWrite);    //将字节数组读入
        while(!out.atEnd())
        {
            qint8 outChar = 0;
            out>>outChar;   //每字节填充一次，直到结束
            QString str = QString("%1").arg(outChar&0xFF,2,16,QLatin1Char('0'));

            message(str+" ");

            rxbyte += str.length();
        }
        //方法二 参考博客http://blog.csdn.net/maowendi/article/details/52209807
        //ui->text_accept->insertPlainText(byteArray.toHex());

    }
    //自动换行
    if(ui->check_auto_line->isChecked())
    {
        message("\r\n");
    }

    displayRxByte(rxbyte);

}

//从串口发送数据
void QTPortDebug::SerialWrite()
{        
     //发送ASCII字符
    if(ui->radio_send_ascii->isChecked())
    {
        //读取要发送的数据
        QString sendData = ui->text_write->toPlainText();

        displaysend(sendData);
        //Unicode转GBK 参考博客问答http://bbs.csdn.net/topics/390024555
        QTextCodec * codec = QTextCodec::codecForName("GBK"); //建立一个unicode与GBK之间的转换器
        QByteArray bytesForGBK = codec->fromUnicode(sendData); //unicode转换成gbk
        //发送数据
        SPort->write(bytesForGBK);

        txbyte += bytesForGBK.length();//发送字节数累加

    }
    //发送16进制字符
    else if(ui->radio_send_hex->isChecked())
    {
        //读取要发送的数据
        QString sendData = ui->text_write->toPlainText();
        //是否显示发送消息
        displaysend(sendData);
       // HexToString
        QByteArray sendbuff;
        //方法一
        QStringtoHex(sendbuff,sendData);
        //方法二
        //sendbuff = QByteArray::fromHex(sendData.toLatin1().data());
        SPort->write(sendbuff);
    }
    //显示发送的字节数
    displayTxByte(txbyte);

}
//打开和关闭串口
void QTPortDebug::on_startbutton_clicked()
{
    if(tr("打开串口") == ui->startbutton->text())
    {

        //写配置信息
        configiniWrite();

        ui->startbutton->setText(tr("关闭串口"));
        getComboBoxValue();
        setPortConfig();
        //收到数据运行槽函数
        if(runonce)//只允许运行一次
        {
           connect(SPort,SIGNAL(readyRead()),this,SLOT(SerialRead()));
        }
        portstatus->setText(tr("Open SerialPort"));
        //statusBar()->addWidget(portstatus);
    }
    else
    {
        //autorun = false;
        //disconnect(SPort);
        runonce = false;

        ui->startbutton->setText(tr("打开串口"));
        SPort->close();

        portstatus->setText("Closed SerialPort");
        //statusBar()->addWidget(portstatus);
        //关闭定时器
        if(timer->isActive())//当定时器已启动
        {
             timer->stop();
        }

    }
}

void QTPortDebug::on_sendbutton_clicked()
{
    if(SPort->isOpen())
    {
        addrecord();//将发送的信息添加到下啦框
        SerialWrite();
        if(ui->check_repsend->isChecked()&&!timer->isActive())//判读定时器未启动
        {
            timer->start(time_cycle);                   //定时器开始计时，其中1000表示1000ms即1秒
        }
    }
    else{
        QMessageBox::warning(this,tr("warning"),tr("亲，请点击继续按钮或打开串口"));
    }

}
//获取当前路径并创建ini对象
void QTPortDebug::config()
{
    setcurrentPath();
    configini = new QSettings(PATH, QSettings::IniFormat);
}
//从ini文件读取并设置为上次配置
void QTPortDebug::configiniRead()
{
    configini->beginGroup("SETUP");
    int i_m_port = configini->value("COM").toInt();
    int i_m_baudrate = configini->value("baudrate").toInt();
    int i_m_databit = configini->value("databit").toInt();
    int i_m_check = configini->value("check").toInt();
    int i_m_stopbit = configini->value("stopbit").toInt();
    int i_m_FlowControl = configini->value("flow").toInt();
    configini->endGroup();

    ui->CB_port->setCurrentIndex(i_m_port);
    ui->CB_baudrate->setCurrentIndex(i_m_baudrate);
    ui->CB_databit->setCurrentIndex(i_m_databit);
    ui->CB_check->setCurrentIndex(i_m_check);
    ui->CB_stopbit->setCurrentIndex(i_m_stopbit);
    ui->CB_flow->setCurrentIndex(i_m_FlowControl);
}
//将配置信息写入ini文件
void QTPortDebug::configiniWrite()
{
    configini->beginGroup("SETUP");
    configini->setValue("COM",ui->CB_port->currentIndex());
    configini->setValue("baudrate",ui->CB_baudrate->currentIndex());
    configini->setValue("databit",ui->CB_databit->currentIndex());
    configini->setValue("check",ui->CB_check->currentIndex());
    configini->setValue("stopbit",ui->CB_stopbit->currentIndex());
    configini->setValue("flow",ui->CB_flow->currentIndex());
    configini->endGroup();
}
//将发送的文本添加到记录
void QTPortDebug::addrecord()
{
    QString str = ui->text_write->toPlainText();
    ui->cb_record->insertItem(0,str);
}
//将记录填充到发送文本框
void QTPortDebug::fillrecord()
{
    ui->text_write->clear();
    QString str = ui->cb_record->currentText();
    ui->text_write->insertPlainText(str);
}
//接收区显示信息
void QTPortDebug::message(QString str)//重载
{
    ui->text_accept->insertPlainText(str);

    QTextCursor cursor = ui->text_accept->textCursor();//将光标移动到文本末尾
    cursor.movePosition(QTextCursor::End);
    ui->text_accept->setTextCursor(cursor);

}

/*void QTPortDebug::message(QString &str)//重载
{
    ui->text_accept->insertPlainText(str);

}*/

char QTPortDebug::ConvertHexChar(char c)
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
void QTPortDebug::QStringtoHex(QByteArray& sendData,QString str)
{
    char hstr,lstr,hdata,ldata;
    int len = str.length();
    int sendnum = 0;
    QByteArray temp;
    temp.resize(len/2);//设置大小，len/2会大于实际16进制字符
    //sendData.resize(len/2);
    for(int i=0;i<len;)
    {
        //hstr = str[i].toAscii();
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
    sendData.reserve(sendnum);
    sendData = temp.left(sendnum);//去掉多余字符
}
void QTPortDebug::CheckAutoRun()
{
    if(SPort->isOpen())
    {
        if(ui->check_repsend->isChecked())
        {
            if(!timer->isActive())
            {
                timer->start(time_cycle);                   //定时器开始计时，其中1000表示1000ms即1秒
            }
        }
        else
        {
            if(timer->isActive())
            {
                timer->stop();

            }
        }
    }
    else{
        QMessageBox::warning(this,tr("warning"),tr("please open SerialPort"));
        ui->check_repsend->setChecked(false);
    }

}

void QTPortDebug::sendupdata()
{
    SerialWrite();
}

void QTPortDebug::displaysend(QString & str)
{
    if(ui->check_display_send->isChecked())
    {
        if(DisplayTimeStatus)
        {
            message(currenttime->currentTime().toString("[hh:mm:ss.zzz]"));
        }
        message(tr("Send data:"));
        message(str);
        message(tr("\r\n"));
    }
}

void QTPortDebug::initStatusbar()
{
    portstatus = new QLabel;
    portstatus->setMinimumSize(120,20);
    portstatus->setAlignment(Qt::AlignLeft);
    statusBar()->addWidget(portstatus);

    rx = new QLabel("RX:");
    rx->setMinimumSize(50,20);
    rx->setAlignment(Qt::AlignHCenter);
    statusBar()->addWidget(rx);

    rxnum = new QLabel("0");
    rxnum->setMinimumSize(50,20);
    rxnum->setAlignment(Qt::AlignHCenter);
    statusBar()->addWidget(rxnum);

    byterx = new QLabel("bytes");
    byterx->setMinimumSize(50,20);
    byterx->setAlignment(Qt::AlignHCenter);
    statusBar()->addWidget(byterx);

    tx = new QLabel("TX:");
    tx->setMinimumSize(50,20);
    tx->setAlignment(Qt::AlignHCenter);
    statusBar()->addWidget(tx);


    txnum = new QLabel("0");
    txnum->setMinimumSize(50,20);
    txnum->setAlignment(Qt::AlignHCenter);
    statusBar()->addWidget(txnum);

    bytetx = new QLabel("bytes");
    bytetx->setMinimumSize(50,20);
    bytetx->setAlignment(Qt::AlignHCenter);
    statusBar()->addWidget(bytetx);
    //设置无边框
    statusBar()->setStyleSheet(QString("QStatusBar::item{border: 0px}"));

}

void QTPortDebug::displayRxByte(unsigned int rxbyte)
{
    QString str = QString::number(rxbyte);
    rxnum->setText(str);

}
void QTPortDebug::displayTxByte(unsigned int txbyte)
{
    QString str = QString::number(txbyte);
    txnum->setText(str);
}

void QTPortDebug::on_Clear_clicked()
{
    rxbyte = 0;//接收字节数
    txbyte = 0;//发送字节数

    rxnum->setText("0");//显示接收字节数0
    txnum->setText("0");//显示发送字节数0

    ui->text_accept->clear();
    ui->text_write->clear();
}

void QTPortDebug::on_sendtime_valueChanged(int arg1)
{
    time_cycle = arg1;
    if(timer->isActive())
    {
        //改变定时时间间隔
        timer->setInterval(time_cycle);
    }
}

void QTPortDebug::on_displaytime_stateChanged(int arg1)
{
    if(ui->displaytime->isChecked())
    {
        DisplayTimeStatus = true;//显示时间

    }
    else{
        DisplayTimeStatus = false;
    }
}


void QTPortDebug::on_pause_clicked()
{
    if(tr("暂  停") == ui->pause->text())
    {
        if(timer->isActive())
        {
            timer->stop();
        }
        if(SPort->isOpen())
        {
            SPort->close();
        }
        ui->pause->setText(tr("继  续"));
    }
    else{
        if(!timer->isActive())
        {
            timer->start();
        }
        if(!SPort->isOpen())
        {
            setPortConfig();
        }
        ui->pause->setText(tr("暂  停"));
    }

}
void QTPortDebug::setground()
{
    palette.setColor(QPalette::Background,QColor(85, 85, 125));
    this->setPalette(palette);
}
