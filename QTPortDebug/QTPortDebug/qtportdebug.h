#ifndef QTPORTDEBUG_H
#define QTPORTDEBUG_H

#include <QMainWindow>
#include <QTranslator>
#include <string>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>//不是QTime
#include <QTime>
#include <QTextCodec>
#include <QSettings>
#include <thread>
#include <string>
#include <windows.h>
#include <QLabel>
#include <QMessageBox>
#include <QDir>
#include <QSpinBox>
#include <QPalette>

namespace Ui {
class QTPortDebug;
}

class QTPortDebug : public QMainWindow
{
    Q_OBJECT
public:
    explicit QTPortDebug(QWidget *parent = 0);
    ~QTPortDebug();

    void getComboBoxValue();
    void iniPort();

private slots:
    void on_startbutton_clicked();
    void on_sendbutton_clicked();

    void SerialRead();
    void SerialWrite();

    void CheckAutoRun();
    void sendupdata();

    void on_Clear_clicked();

    void fillrecord();

    //void changetimecycle(int time);
    void on_sendtime_valueChanged(int arg1);

    void on_displaytime_stateChanged(int arg1);

    void on_pause_clicked();

private:
    Ui::QTPortDebug *ui;

    QString m_port;
    QString m_baudrate;
    QString m_databit;
    QString m_check;
    QString m_stopbit;
    QString m_FlowControl ;


    //ini类
    QSettings* configini;
    //串口类
    QSerialPort* SPort;

    bool runonce;
    //定时器
    QTimer * timer;
    //显示当前那时间
    QTime * currenttime;
    bool DisplayTimeStatus;
    //时间间隔time_cycle ms发送一次
   /*QSpinBox * gettime;*/
    int time_cycle;
    //ini路径
    QString PATH;
    QDir * currentPath;
    //状态栏
    QLabel* portstatus;
    QLabel* rx;
    QLabel* tx;
    QLabel* byterx;
    QLabel* bytetx;
    QLabel* rxnum;
    QLabel* txnum;

    QPalette palette;

private:
    void setPortConfig();

    void config();
    void configiniRead();
    void configiniWrite();

    void setcurrentPath();

    void addrecord();

    //显示消息
    void message(QString str);
   // void message(QString & str);
    //发送16进制
    char ConvertHexChar(char c);
    void QStringtoHex(QByteArray& sendData,QString str);
    //显示发送
    void displaysend(QString& str);
    //初始化状态栏
    void initStatusbar();
    //状态栏显示接受和发送的字节数
    unsigned int rxbyte;
    unsigned int txbyte;
    void displayRxByte(unsigned int rxbyte);
    void displayTxByte(unsigned int txbyte);

    void setground();
};

#endif // QTPORTDEBUG_H
