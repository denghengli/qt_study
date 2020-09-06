/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *groupBox;
    QRadioButton *radioBtn_woman;
    QRadioButton *radioBtn_man;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_3;
    QGroupBox *groupBox_3;
    QCheckBox *checkBox_serv;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QCommandLinkButton *commandLinkButton;
    QDialogButtonBox *buttonBox;
    QListWidget *listWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_login;
    QToolButton *toolButton_set;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(660, 409);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(130, 10, 120, 80));
        radioBtn_woman = new QRadioButton(groupBox);
        radioBtn_woman->setObjectName(QStringLiteral("radioBtn_woman"));
        radioBtn_woman->setGeometry(QRect(30, 50, 115, 19));
        radioBtn_man = new QRadioButton(groupBox);
        radioBtn_man->setObjectName(QStringLiteral("radioBtn_man"));
        radioBtn_man->setGeometry(QRect(30, 20, 115, 19));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(280, 10, 120, 80));
        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(30, 50, 115, 19));
        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(30, 20, 115, 19));
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(30, 110, 151, 141));
        checkBox_serv = new QCheckBox(groupBox_3);
        checkBox_serv->setObjectName(QStringLiteral("checkBox_serv"));
        checkBox_serv->setGeometry(QRect(40, 90, 91, 19));
        checkBox_2 = new QCheckBox(groupBox_3);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(40, 60, 91, 19));
        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(40, 30, 91, 19));
        commandLinkButton = new QCommandLinkButton(Widget);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(30, 250, 187, 41));
        buttonBox = new QDialogButtonBox(Widget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 310, 193, 28));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(220, 110, 256, 192));
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 10, 95, 88));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_login = new QPushButton(widget);
        pushButton_login->setObjectName(QStringLiteral("pushButton_login"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_login->setIcon(icon);
        pushButton_login->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(pushButton_login);

        toolButton_set = new QToolButton(widget);
        toolButton_set->setObjectName(QStringLiteral("toolButton_set"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/1.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_set->setIcon(icon1);
        toolButton_set->setIconSize(QSize(32, 32));
        toolButton_set->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_set->setAutoRaise(true);

        verticalLayout->addWidget(toolButton_set);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        groupBox->setTitle(QApplication::translate("Widget", "\346\200\247\345\210\253", 0));
        radioBtn_woman->setText(QApplication::translate("Widget", "\345\245\263", 0));
        radioBtn_man->setText(QApplication::translate("Widget", "\347\224\267", 0));
        groupBox_2->setTitle(QApplication::translate("Widget", "\345\251\232\345\220\246", 0));
        radioButton_4->setText(QApplication::translate("Widget", "\346\234\252\345\251\232", 0));
        radioButton_3->setText(QApplication::translate("Widget", "\345\267\262\345\251\232", 0));
        groupBox_3->setTitle(QApplication::translate("Widget", "\351\227\256\345\215\267\350\260\203\346\237\245", 0));
        checkBox_serv->setText(QApplication::translate("Widget", "\346\234\215\345\212\241\345\217\267", 0));
        checkBox_2->setText(QApplication::translate("Widget", "\345\217\243\346\204\237\345\245\275", 0));
        checkBox->setText(QApplication::translate("Widget", "\344\273\267\346\240\274\345\256\236\346\203\240", 0));
        commandLinkButton->setText(QApplication::translate("Widget", "CommandLinkButton", 0));
        pushButton_login->setText(QApplication::translate("Widget", "\347\231\273\345\275\225", 0));
        toolButton_set->setText(QApplication::translate("Widget", "\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
