/********************************************************************************
** Form generated from reading UI file 'serialport.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORT_H
#define UI_SERIALPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialPort
{
public:
    QAction *actionSend;
    QWidget *centralWidget;
    QGridLayout *gridLayout_16;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QLabel *label_port;
    QComboBox *CB_port;
    QLabel *label_baudrate;
    QComboBox *CB_baudrate;
    QLabel *label_databit;
    QComboBox *CB_databit;
    QLabel *label_checkbit;
    QComboBox *CB_checkbit;
    QLabel *label_stopbit;
    QComboBox *CB_stopbit;
    QLabel *label_open;
    QPushButton *Btn_open;
    QGridLayout *gridLayout_5;
    QPushButton *Btn_save;
    QPushButton *Btn_clearrx;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QCheckBox *checkBox_rx_dispsend;
    QCheckBox *checkBox_rx_hexdisp;
    QCheckBox *checkBox_rx_autoline;
    QCheckBox *checkBox_rx_disptime;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QTextEdit *textEdit_rx;
    QGridLayout *gridLayout_15;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_14;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBox_tx_newline;
    QCheckBox *checkBox_tx_hexsend;
    QCheckBox *checkBox_tx_delayed;
    QWidget *widget;
    QGridLayout *gridLayout_11;
    QLabel *label;
    QLineEdit *lineEdit_period;
    QGridLayout *gridLayout_10;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_9;
    QTextEdit *textEdit_tx;
    QGridLayout *gridLayout_12;
    QLineEdit *lineEdit_file;
    QPushButton *Btn_openfile;
    QPushButton *Btn_sendfile;
    QPushButton *Btn_stopsend;
    QGridLayout *gridLayout_13;
    QPushButton *Btn_send;
    QPushButton *Btn_cleartx;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SerialPort)
    {
        if (SerialPort->objectName().isEmpty())
            SerialPort->setObjectName(QStringLiteral("SerialPort"));
        SerialPort->resize(818, 725);
        actionSend = new QAction(SerialPort);
        actionSend->setObjectName(QStringLiteral("actionSend"));
        centralWidget = new QWidget(SerialPort);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_16 = new QGridLayout(centralWidget);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        groupBox_3->setFont(font);
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_port = new QLabel(groupBox_3);
        label_port->setObjectName(QStringLiteral("label_port"));
        label_port->setFont(font);

        gridLayout->addWidget(label_port, 0, 0, 1, 1);

        CB_port = new QComboBox(groupBox_3);
        CB_port->setObjectName(QStringLiteral("CB_port"));

        gridLayout->addWidget(CB_port, 0, 1, 1, 1);

        label_baudrate = new QLabel(groupBox_3);
        label_baudrate->setObjectName(QStringLiteral("label_baudrate"));
        label_baudrate->setFont(font);

        gridLayout->addWidget(label_baudrate, 1, 0, 1, 1);

        CB_baudrate = new QComboBox(groupBox_3);
        CB_baudrate->setObjectName(QStringLiteral("CB_baudrate"));

        gridLayout->addWidget(CB_baudrate, 1, 1, 1, 1);

        label_databit = new QLabel(groupBox_3);
        label_databit->setObjectName(QStringLiteral("label_databit"));
        label_databit->setFont(font);

        gridLayout->addWidget(label_databit, 2, 0, 1, 1);

        CB_databit = new QComboBox(groupBox_3);
        CB_databit->setObjectName(QStringLiteral("CB_databit"));

        gridLayout->addWidget(CB_databit, 2, 1, 1, 1);

        label_checkbit = new QLabel(groupBox_3);
        label_checkbit->setObjectName(QStringLiteral("label_checkbit"));
        label_checkbit->setFont(font);

        gridLayout->addWidget(label_checkbit, 3, 0, 1, 1);

        CB_checkbit = new QComboBox(groupBox_3);
        CB_checkbit->setObjectName(QStringLiteral("CB_checkbit"));

        gridLayout->addWidget(CB_checkbit, 3, 1, 1, 1);

        label_stopbit = new QLabel(groupBox_3);
        label_stopbit->setObjectName(QStringLiteral("label_stopbit"));
        label_stopbit->setFont(font);

        gridLayout->addWidget(label_stopbit, 4, 0, 1, 1);

        CB_stopbit = new QComboBox(groupBox_3);
        CB_stopbit->setObjectName(QStringLiteral("CB_stopbit"));

        gridLayout->addWidget(CB_stopbit, 4, 1, 1, 1);

        label_open = new QLabel(groupBox_3);
        label_open->setObjectName(QStringLiteral("label_open"));
        label_open->setFont(font);

        gridLayout->addWidget(label_open, 5, 0, 1, 1);

        Btn_open = new QPushButton(groupBox_3);
        Btn_open->setObjectName(QStringLiteral("Btn_open"));
        Btn_open->setFont(font);

        gridLayout->addWidget(Btn_open, 5, 1, 1, 1);


        gridLayout_6->addWidget(groupBox_3, 0, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        Btn_save = new QPushButton(centralWidget);
        Btn_save->setObjectName(QStringLiteral("Btn_save"));
        Btn_save->setFont(font);

        gridLayout_5->addWidget(Btn_save, 0, 0, 1, 1);

        Btn_clearrx = new QPushButton(centralWidget);
        Btn_clearrx->setObjectName(QStringLiteral("Btn_clearrx"));
        Btn_clearrx->setFont(font);

        gridLayout_5->addWidget(Btn_clearrx, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        checkBox_rx_dispsend = new QCheckBox(groupBox);
        checkBox_rx_dispsend->setObjectName(QStringLiteral("checkBox_rx_dispsend"));

        gridLayout_3->addWidget(checkBox_rx_dispsend, 3, 0, 1, 1);

        checkBox_rx_hexdisp = new QCheckBox(groupBox);
        checkBox_rx_hexdisp->setObjectName(QStringLiteral("checkBox_rx_hexdisp"));

        gridLayout_3->addWidget(checkBox_rx_hexdisp, 0, 0, 1, 1);

        checkBox_rx_autoline = new QCheckBox(groupBox);
        checkBox_rx_autoline->setObjectName(QStringLiteral("checkBox_rx_autoline"));

        gridLayout_3->addWidget(checkBox_rx_autoline, 1, 0, 1, 1);

        checkBox_rx_disptime = new QCheckBox(groupBox);
        checkBox_rx_disptime->setObjectName(QStringLiteral("checkBox_rx_disptime"));

        gridLayout_3->addWidget(checkBox_rx_disptime, 2, 0, 1, 1);


        gridLayout_7->addWidget(groupBox, 1, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_7, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        groupBox_4->setFont(font1);
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        textEdit_rx = new QTextEdit(groupBox_4);
        textEdit_rx->setObjectName(QStringLiteral("textEdit_rx"));

        gridLayout_4->addWidget(textEdit_rx, 0, 0, 1, 1);


        gridLayout_8->addWidget(groupBox_4, 0, 1, 1, 1);


        gridLayout_16->addLayout(gridLayout_8, 0, 0, 1, 1);

        gridLayout_15 = new QGridLayout();
        gridLayout_15->setSpacing(6);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(195, 180));
        groupBox_2->setMaximumSize(QSize(195, 180));
        groupBox_2->setFont(font);
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        gridLayout_14 = new QGridLayout(groupBox_2);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        checkBox_tx_newline = new QCheckBox(groupBox_2);
        checkBox_tx_newline->setObjectName(QStringLiteral("checkBox_tx_newline"));

        gridLayout_2->addWidget(checkBox_tx_newline, 0, 0, 1, 1);

        checkBox_tx_hexsend = new QCheckBox(groupBox_2);
        checkBox_tx_hexsend->setObjectName(QStringLiteral("checkBox_tx_hexsend"));

        gridLayout_2->addWidget(checkBox_tx_hexsend, 1, 0, 1, 1);

        checkBox_tx_delayed = new QCheckBox(groupBox_2);
        checkBox_tx_delayed->setObjectName(QStringLiteral("checkBox_tx_delayed"));

        gridLayout_2->addWidget(checkBox_tx_delayed, 2, 0, 1, 1);

        widget = new QWidget(groupBox_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(170, 35));
        widget->setMaximumSize(QSize(170, 35));
        gridLayout_11 = new QGridLayout(widget);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_11->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout_11->setContentsMargins(0, 7, 11, -1);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(90, 23));
        label->setMaximumSize(QSize(90, 16777215));

        gridLayout_11->addWidget(label, 0, 0, 1, 1);

        lineEdit_period = new QLineEdit(widget);
        lineEdit_period->setObjectName(QStringLiteral("lineEdit_period"));
        lineEdit_period->setMinimumSize(QSize(75, 20));
        lineEdit_period->setMaximumSize(QSize(75, 20));

        gridLayout_11->addWidget(lineEdit_period, 0, 1, 1, 1);


        gridLayout_2->addWidget(widget, 3, 0, 1, 1);


        gridLayout_14->addLayout(gridLayout_2, 0, 0, 1, 1);


        gridLayout_15->addWidget(groupBox_2, 0, 0, 1, 1);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setFont(font1);
        gridLayout_9 = new QGridLayout(groupBox_5);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        textEdit_tx = new QTextEdit(groupBox_5);
        textEdit_tx->setObjectName(QStringLiteral("textEdit_tx"));
        textEdit_tx->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);

        gridLayout_9->addWidget(textEdit_tx, 0, 0, 1, 1);


        gridLayout_10->addWidget(groupBox_5, 0, 0, 1, 1);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setSpacing(6);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        lineEdit_file = new QLineEdit(centralWidget);
        lineEdit_file->setObjectName(QStringLiteral("lineEdit_file"));

        gridLayout_12->addWidget(lineEdit_file, 0, 0, 1, 1);

        Btn_openfile = new QPushButton(centralWidget);
        Btn_openfile->setObjectName(QStringLiteral("Btn_openfile"));
        Btn_openfile->setFont(font);
        Btn_openfile->setAutoDefault(false);

        gridLayout_12->addWidget(Btn_openfile, 0, 1, 1, 1);

        Btn_sendfile = new QPushButton(centralWidget);
        Btn_sendfile->setObjectName(QStringLiteral("Btn_sendfile"));
        Btn_sendfile->setFont(font);
        Btn_sendfile->setAutoDefault(false);

        gridLayout_12->addWidget(Btn_sendfile, 0, 2, 1, 1);

        Btn_stopsend = new QPushButton(centralWidget);
        Btn_stopsend->setObjectName(QStringLiteral("Btn_stopsend"));
        Btn_stopsend->setFont(font);
        Btn_stopsend->setAutoDefault(false);

        gridLayout_12->addWidget(Btn_stopsend, 0, 3, 1, 1);


        gridLayout_10->addLayout(gridLayout_12, 1, 0, 1, 2);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setSpacing(6);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        Btn_send = new QPushButton(centralWidget);
        Btn_send->setObjectName(QStringLiteral("Btn_send"));
        Btn_send->setFont(font);
        Btn_send->setCursor(QCursor(Qt::UpArrowCursor));
        Btn_send->setAutoRepeatDelay(297);

        gridLayout_13->addWidget(Btn_send, 0, 0, 1, 1);

        Btn_cleartx = new QPushButton(centralWidget);
        Btn_cleartx->setObjectName(QStringLiteral("Btn_cleartx"));
        Btn_cleartx->setFont(font);
        Btn_cleartx->setAutoDefault(false);

        gridLayout_13->addWidget(Btn_cleartx, 1, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_13, 0, 1, 1, 1);


        gridLayout_15->addLayout(gridLayout_10, 0, 1, 1, 1);


        gridLayout_16->addLayout(gridLayout_15, 1, 0, 1, 1);

        SerialPort->setCentralWidget(centralWidget);
        groupBox_4->raise();
        groupBox_5->raise();
        lineEdit_period->raise();
        groupBox_2->raise();
        statusBar = new QStatusBar(SerialPort);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SerialPort->setStatusBar(statusBar);

        retranslateUi(SerialPort);

        QMetaObject::connectSlotsByName(SerialPort);
    } // setupUi

    void retranslateUi(QMainWindow *SerialPort)
    {
        SerialPort->setWindowTitle(QApplication::translate("SerialPort", "SerialPort", 0));
        actionSend->setText(QApplication::translate("SerialPort", "S:", 0));
        groupBox_3->setTitle(QApplication::translate("SerialPort", "\344\270\262\345\217\243\350\256\276\347\275\256", 0));
        label_port->setText(QApplication::translate("SerialPort", "\344\270\262\345\217\243\345\217\267", 0));
        label_baudrate->setText(QApplication::translate("SerialPort", "\346\263\242\347\211\271\347\216\207", 0));
        CB_baudrate->clear();
        CB_baudrate->insertItems(0, QStringList()
         << QApplication::translate("SerialPort", "9600", 0)
         << QApplication::translate("SerialPort", "38400", 0)
         << QApplication::translate("SerialPort", "56700", 0)
         << QApplication::translate("SerialPort", "115200", 0)
         << QApplication::translate("SerialPort", "119600", 0)
        );
        CB_baudrate->setCurrentText(QApplication::translate("SerialPort", "9600", 0));
        label_databit->setText(QApplication::translate("SerialPort", "\346\225\260\346\215\256\344\275\215", 0));
        CB_databit->clear();
        CB_databit->insertItems(0, QStringList()
         << QApplication::translate("SerialPort", "5", 0)
         << QApplication::translate("SerialPort", "6", 0)
         << QApplication::translate("SerialPort", "7", 0)
         << QApplication::translate("SerialPort", "8", 0)
        );
        label_checkbit->setText(QApplication::translate("SerialPort", "\346\240\241\351\252\214\344\275\215", 0));
        CB_checkbit->clear();
        CB_checkbit->insertItems(0, QStringList()
         << QApplication::translate("SerialPort", "None", 0)
         << QApplication::translate("SerialPort", "\345\245\207\346\240\241\351\252\214", 0)
         << QApplication::translate("SerialPort", "\345\201\266\346\240\241\351\252\214", 0)
        );
        label_stopbit->setText(QApplication::translate("SerialPort", "\345\201\234\346\255\242\344\275\215", 0));
        CB_stopbit->clear();
        CB_stopbit->insertItems(0, QStringList()
         << QApplication::translate("SerialPort", "1", 0)
         << QApplication::translate("SerialPort", "2", 0)
        );
        label_open->setText(QApplication::translate("SerialPort", "\344\270\262\345\217\243\346\223\215\344\275\234", 0));
        Btn_open->setText(QApplication::translate("SerialPort", "\346\211\223\345\274\200", 0));
        Btn_save->setText(QApplication::translate("SerialPort", "\344\277\235\345\255\230\347\252\227\345\217\243", 0));
        Btn_clearrx->setText(QApplication::translate("SerialPort", "\346\270\205\351\231\244\346\216\245\346\224\266", 0));
        groupBox->setTitle(QApplication::translate("SerialPort", "\346\216\245\346\224\266\350\256\276\347\275\256", 0));
        checkBox_rx_dispsend->setText(QApplication::translate("SerialPort", "\346\230\276\347\244\272\345\217\221\351\200\201", 0));
        checkBox_rx_hexdisp->setText(QApplication::translate("SerialPort", "16\350\277\233\345\210\266\346\230\276\347\244\272", 0));
        checkBox_rx_autoline->setText(QApplication::translate("SerialPort", "\350\207\252\345\212\250\346\215\242\350\241\214", 0));
        checkBox_rx_disptime->setText(QApplication::translate("SerialPort", "\346\230\276\347\244\272\346\227\266\351\227\264", 0));
        groupBox_4->setTitle(QApplication::translate("SerialPort", "\344\270\262\345\217\243\346\216\245\346\224\266\346\225\260\346\215\256", 0));
        groupBox_2->setTitle(QApplication::translate("SerialPort", "\345\217\221\351\200\201\350\256\276\347\275\256", 0));
        checkBox_tx_newline->setText(QApplication::translate("SerialPort", "\345\217\221\351\200\201\346\226\260\350\241\214", 0));
        checkBox_tx_hexsend->setText(QApplication::translate("SerialPort", "16\350\277\233\345\210\266\345\217\221\351\200\201", 0));
        checkBox_tx_delayed->setText(QApplication::translate("SerialPort", "\345\256\232\346\227\266\345\217\221\351\200\201", 0));
        label->setText(QApplication::translate("SerialPort", "\345\221\250\346\234\237(ms)\357\274\232", 0));
        groupBox_5->setTitle(QString());
        Btn_openfile->setText(QApplication::translate("SerialPort", "\346\211\223\345\274\200\346\226\207\344\273\266", 0));
        Btn_sendfile->setText(QApplication::translate("SerialPort", "\345\217\221\351\200\201\346\226\207\344\273\266", 0));
        Btn_stopsend->setText(QApplication::translate("SerialPort", "\345\201\234\346\255\242\345\217\221\351\200\201", 0));
        Btn_send->setText(QApplication::translate("SerialPort", "\345\217\221\351\200\201", 0));
        Btn_cleartx->setText(QApplication::translate("SerialPort", "\346\270\205\351\231\244\345\217\221\351\200\201", 0));
    } // retranslateUi

};

namespace Ui {
    class SerialPort: public Ui_SerialPort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORT_H
