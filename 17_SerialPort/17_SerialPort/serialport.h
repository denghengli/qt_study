#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QSettings>
#include <QTimer>
#include <QTime>
#include <QDir>
#include <QLabel>

namespace Ui {
class SerialPort;
}

class SerialPort : public QMainWindow
{
    Q_OBJECT

public:
    explicit SerialPort(QWidget *parent = 0);
    ~SerialPort();

    void initPort();//初始化串口
    void getComboBoxValue();//获取配置项值

private slots:
    void openbtn_clicked();
    void savebtn_clicked();
    void clrrxbtn_clicked();
    void sendbtn_clicked();
    void clrtxbtn_clicked();
    void stopsendbtn_clicked();
    void openfilebtn_clicked();
    void sendfilebtn_clicked();
    void delayedcB_changed();//定时发送状态改变
    void hexsendcB_changed();//16进制发送状态改变

    void serial_read();
    void serial_write();

private:
    Ui::SerialPort *ui;

    //下拉框配置项的文本值
    QString str_port;
    QString str_baudrate;
    QString str_databit;
    QString str_checkbit;
    QString str_stopbit;

    //串口类
    QSerialPort *port;
    //ini类,用于访问存储在名为iniFilename的文件中的设置。如果文件不存在，就创建它
    QSettings *configini;

    //ini路径
    QDir *iniPath;
    QString iniFilename;
    //定时发送定时器
    QTimer *delayed_timer;
    int delayed_period = 1000;//ms
    //当前时间
    QTimer *freshTimer;
    QTime *curTime;

    //串口是否打开
    bool isOpen = false;
    //接收和发送的字节数
    int rxBytes = 0;
    int txBytes = 0;

    //状态栏
    QLabel *portStatus;
    QLabel *rxStatus;
    QLabel *txStatus;
    QLabel *curTimeStatus;

    //保存文件的文件路径名
    QString openfile_path = NULL;
    QString savefile_path = NULL;
    bool savefile_flag;

private:
    void initStatusbar();//初始化状态栏
    void portconfig();//串口配置
    void configiniInit();//创建ini配置文件
    void configiniRead();//读取ini配置文件
    void configiniWrite();//写ini配置文件
    void display_message(QString str);//在接收区显示数据(从串口读取的和发送的)
    //发送16进制
    char ConvertHexChar(char c);
    void QStringtoHex(QByteArray& sendData,QString str);
};

#endif // SERIALPORT_H
