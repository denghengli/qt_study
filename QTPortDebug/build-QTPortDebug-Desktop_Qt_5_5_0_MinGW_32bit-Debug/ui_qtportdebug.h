/********************************************************************************
** Form generated from reading UI file 'qtportdebug.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTPORTDEBUG_H
#define UI_QTPORTDEBUG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTPortDebug
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_7;
    QPushButton *pause;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radio_send_ascii;
    QRadioButton *radio_send_hex;
    QCheckBox *check_repsend;
    QSpinBox *sendtime;
    QGridLayout *gridLayout_4;
    QTextEdit *text_write;
    QGridLayout *gridLayout_6;
    QPushButton *sendbutton;
    QCheckBox *displaytime;
    QPushButton *Clear;
    QComboBox *cb_record;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QComboBox *CB_flow;
    QLabel *label_5;
    QComboBox *CB_databit;
    QComboBox *CB_check;
    QComboBox *CB_port;
    QLabel *label_2;
    QLabel *label_4;
    QComboBox *CB_baudrate;
    QLabel *label_6;
    QComboBox *CB_stopbit;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_2;
    QPushButton *startbutton;
    QGroupBox *groupBox;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radio_accept_ascii;
    QRadioButton *radio_accept_hex;
    QCheckBox *check_display_send;
    QCheckBox *check_auto_line;
    QTextEdit *text_accept;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QTPortDebug)
    {
        if (QTPortDebug->objectName().isEmpty())
            QTPortDebug->setObjectName(QStringLiteral("QTPortDebug"));
        QTPortDebug->resize(645, 581);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QTPortDebug->sizePolicy().hasHeightForWidth());
        QTPortDebug->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(QTPortDebug);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_8 = new QGridLayout(centralWidget);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        pause = new QPushButton(centralWidget);
        pause->setObjectName(QStringLiteral("pause"));
        pause->setMinimumSize(QSize(60, 35));

        gridLayout_7->addWidget(pause, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(129, 101));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 129, 77));
        gridLayout_5 = new QGridLayout(layoutWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        radio_send_ascii = new QRadioButton(layoutWidget);
        radio_send_ascii->setObjectName(QStringLiteral("radio_send_ascii"));

        horizontalLayout_2->addWidget(radio_send_ascii);

        radio_send_hex = new QRadioButton(layoutWidget);
        radio_send_hex->setObjectName(QStringLiteral("radio_send_hex"));

        horizontalLayout_2->addWidget(radio_send_hex);


        gridLayout_5->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        check_repsend = new QCheckBox(layoutWidget);
        check_repsend->setObjectName(QStringLiteral("check_repsend"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(check_repsend->sizePolicy().hasHeightForWidth());
        check_repsend->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(check_repsend, 1, 0, 1, 1);

        sendtime = new QSpinBox(layoutWidget);
        sendtime->setObjectName(QStringLiteral("sendtime"));
        sendtime->setMaximumSize(QSize(60, 16777215));
        sendtime->setMinimum(100);
        sendtime->setMaximum(10000000);
        sendtime->setSingleStep(1);
        sendtime->setValue(1000);
        sendtime->setDisplayIntegerBase(10);

        gridLayout_5->addWidget(sendtime, 2, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_2, 1, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_7, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        text_write = new QTextEdit(centralWidget);
        text_write->setObjectName(QStringLiteral("text_write"));
        text_write->setMinimumSize(QSize(0, 110));
        text_write->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(text_write, 0, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        sendbutton = new QPushButton(centralWidget);
        sendbutton->setObjectName(QStringLiteral("sendbutton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sendbutton->sizePolicy().hasHeightForWidth());
        sendbutton->setSizePolicy(sizePolicy2);
        sendbutton->setMinimumSize(QSize(60, 37));

        gridLayout_6->addWidget(sendbutton, 2, 0, 1, 1);

        displaytime = new QCheckBox(centralWidget);
        displaytime->setObjectName(QStringLiteral("displaytime"));

        gridLayout_6->addWidget(displaytime, 0, 0, 1, 1);

        Clear = new QPushButton(centralWidget);
        Clear->setObjectName(QStringLiteral("Clear"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Clear->sizePolicy().hasHeightForWidth());
        Clear->setSizePolicy(sizePolicy3);
        Clear->setMinimumSize(QSize(60, 35));
        Clear->setMaximumSize(QSize(16777215, 300));

        gridLayout_6->addWidget(Clear, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_6, 0, 1, 1, 1);

        cb_record = new QComboBox(centralWidget);
        cb_record->setObjectName(QStringLiteral("cb_record"));

        gridLayout_4->addWidget(cb_record, 1, 0, 1, 2);


        gridLayout_9->addLayout(gridLayout_4, 0, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout_9, 2, 0, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 20));

        verticalLayout->addWidget(label_3);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        CB_flow = new QComboBox(centralWidget);
        CB_flow->setObjectName(QStringLiteral("CB_flow"));
        CB_flow->setMinimumSize(QSize(76, 23));

        gridLayout->addWidget(CB_flow, 5, 1, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy4.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        CB_databit = new QComboBox(centralWidget);
        CB_databit->setObjectName(QStringLiteral("CB_databit"));
        sizePolicy4.setHeightForWidth(CB_databit->sizePolicy().hasHeightForWidth());
        CB_databit->setSizePolicy(sizePolicy4);
        CB_databit->setMinimumSize(QSize(76, 23));

        gridLayout->addWidget(CB_databit, 2, 1, 1, 1);

        CB_check = new QComboBox(centralWidget);
        CB_check->setObjectName(QStringLiteral("CB_check"));
        CB_check->setMinimumSize(QSize(76, 23));

        gridLayout->addWidget(CB_check, 3, 1, 1, 1);

        CB_port = new QComboBox(centralWidget);
        CB_port->setObjectName(QStringLiteral("CB_port"));
        CB_port->setMinimumSize(QSize(85, 23));

        gridLayout->addWidget(CB_port, 0, 1, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy4.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy4);
        label_2->setMaximumSize(QSize(16777215, 12));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy4.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy4);
        label_4->setMaximumSize(QSize(16777215, 12));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        CB_baudrate = new QComboBox(centralWidget);
        CB_baudrate->setObjectName(QStringLiteral("CB_baudrate"));
        CB_baudrate->setMinimumSize(QSize(76, 23));

        gridLayout->addWidget(CB_baudrate, 1, 1, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy4.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        CB_stopbit = new QComboBox(centralWidget);
        CB_stopbit->setObjectName(QStringLiteral("CB_stopbit"));
        CB_stopbit->setMinimumSize(QSize(76, 23));

        gridLayout->addWidget(CB_stopbit, 4, 1, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy4.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(label_7, 4, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        startbutton = new QPushButton(centralWidget);
        startbutton->setObjectName(QStringLiteral("startbutton"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(startbutton->sizePolicy().hasHeightForWidth());
        startbutton->setSizePolicy(sizePolicy5);
        startbutton->setMinimumSize(QSize(130, 40));
        startbutton->setMaximumSize(QSize(16777215, 200));

        verticalLayout_2->addWidget(startbutton);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(129, 102));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 30, 129, 75));
        gridLayout_3 = new QGridLayout(layoutWidget1);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radio_accept_ascii = new QRadioButton(layoutWidget1);
        radio_accept_ascii->setObjectName(QStringLiteral("radio_accept_ascii"));

        horizontalLayout->addWidget(radio_accept_ascii);

        radio_accept_hex = new QRadioButton(layoutWidget1);
        radio_accept_hex->setObjectName(QStringLiteral("radio_accept_hex"));
        radio_accept_hex->setMaximumSize(QSize(16700000, 16777215));

        horizontalLayout->addWidget(radio_accept_hex);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        check_display_send = new QCheckBox(layoutWidget1);
        check_display_send->setObjectName(QStringLiteral("check_display_send"));

        gridLayout_3->addWidget(check_display_send, 1, 0, 1, 1);

        check_auto_line = new QCheckBox(layoutWidget1);
        check_auto_line->setObjectName(QStringLiteral("check_auto_line"));

        gridLayout_3->addWidget(check_auto_line, 2, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox);


        verticalLayout_3->addLayout(verticalLayout_2);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);

        text_accept = new QTextEdit(centralWidget);
        text_accept->setObjectName(QStringLiteral("text_accept"));
        text_accept->setMouseTracking(true);

        gridLayout_2->addWidget(text_accept, 0, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout_2, 0, 0, 2, 2);

        QTPortDebug->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QTPortDebug);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QTPortDebug->setStatusBar(statusBar);

        retranslateUi(QTPortDebug);

        QMetaObject::connectSlotsByName(QTPortDebug);
    } // setupUi

    void retranslateUi(QMainWindow *QTPortDebug)
    {
        QTPortDebug->setWindowTitle(QApplication::translate("QTPortDebug", "QTPortDebug", 0));
        pause->setText(QApplication::translate("QTPortDebug", "\346\232\202  \345\201\234", 0));
        groupBox_2->setTitle(QApplication::translate("QTPortDebug", "\345\217\221\351\200\201\350\256\276\347\275\256", 0));
        radio_send_ascii->setText(QApplication::translate("QTPortDebug", "ASCII", 0));
        radio_send_hex->setText(QApplication::translate("QTPortDebug", "Hex", 0));
        check_repsend->setText(QApplication::translate("QTPortDebug", "\351\207\215\345\244\215\345\217\221\351\200\201", 0));
        sendtime->setSuffix(QApplication::translate("QTPortDebug", "ms", 0));
        sendbutton->setText(QApplication::translate("QTPortDebug", "\345\217\221  \351\200\201", 0));
        displaytime->setText(QApplication::translate("QTPortDebug", "\346\230\276\347\244\272\346\227\266\351\227\264", 0));
        Clear->setText(QApplication::translate("QTPortDebug", "\346\270\205  \347\251\272", 0));
        label_3->setText(QApplication::translate("QTPortDebug", "\344\270\262\345\217\243\350\256\276\347\275\256", 0));
        label_8->setText(QApplication::translate("QTPortDebug", "\346\265\201  \346\216\247", 0));
        CB_flow->clear();
        CB_flow->insertItems(0, QStringList()
         << QApplication::translate("QTPortDebug", "None", 0)
         << QApplication::translate("QTPortDebug", "XON/XOFF", 0)
         << QApplication::translate("QTPortDebug", "CTS/RTS", 0)
        );
        label_5->setText(QApplication::translate("QTPortDebug", "\346\225\260\346\215\256\344\275\215", 0));
        CB_databit->clear();
        CB_databit->insertItems(0, QStringList()
         << QApplication::translate("QTPortDebug", "5", 0)
         << QApplication::translate("QTPortDebug", "6", 0)
         << QApplication::translate("QTPortDebug", "7", 0)
         << QApplication::translate("QTPortDebug", "8", 0)
        );
        CB_check->clear();
        CB_check->insertItems(0, QStringList()
         << QApplication::translate("QTPortDebug", "None", 0)
         << QApplication::translate("QTPortDebug", "Even", 0)
         << QApplication::translate("QTPortDebug", "Odd", 0)
         << QApplication::translate("QTPortDebug", "Space", 0)
         << QApplication::translate("QTPortDebug", "Mark", 0)
        );
        label_2->setText(QApplication::translate("QTPortDebug", "\346\263\242\347\211\271\347\216\207", 0));
        label_4->setText(QApplication::translate("QTPortDebug", "\344\270\262  \345\217\243", 0));
        CB_baudrate->clear();
        CB_baudrate->insertItems(0, QStringList()
         << QApplication::translate("QTPortDebug", "9600", 0)
         << QApplication::translate("QTPortDebug", "38400", 0)
         << QApplication::translate("QTPortDebug", "57600", 0)
         << QApplication::translate("QTPortDebug", "115200", 0)
         << QApplication::translate("QTPortDebug", "119600", 0)
        );
        label_6->setText(QApplication::translate("QTPortDebug", "\346\240\241\351\252\214\344\275\215", 0));
        CB_stopbit->clear();
        CB_stopbit->insertItems(0, QStringList()
         << QApplication::translate("QTPortDebug", "1", 0)
         << QApplication::translate("QTPortDebug", "2", 0)
        );
        label_7->setText(QApplication::translate("QTPortDebug", "\345\201\234\346\255\242\344\275\215", 0));
        startbutton->setText(QApplication::translate("QTPortDebug", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
        groupBox->setTitle(QApplication::translate("QTPortDebug", "\346\216\245\346\224\266\350\256\276\347\275\256", 0));
        radio_accept_ascii->setText(QApplication::translate("QTPortDebug", "ASCII", 0));
        radio_accept_hex->setText(QApplication::translate("QTPortDebug", "Hex", 0));
        check_display_send->setText(QApplication::translate("QTPortDebug", "\346\230\276\347\244\272\345\217\221\351\200\201", 0));
        check_auto_line->setText(QApplication::translate("QTPortDebug", "\350\207\252\345\212\250\346\215\242\350\241\214", 0));
    } // retranslateUi

};

namespace Ui {
    class QTPortDebug: public Ui_QTPortDebug {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTPORTDEBUG_H
