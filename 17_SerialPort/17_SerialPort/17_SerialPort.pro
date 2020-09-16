#-------------------------------------------------
#
# Project created by QtCreator 2020-09-10T23:11:37
#
#-------------------------------------------------

QT       += core gui serialport
CONFIG   += c++11
TRANSLATIONS += zh_CN.ts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 17_SerialPort
TEMPLATE = app


SOURCES += main.cpp\
        serialport.cpp

HEADERS  += serialport.h

FORMS    += serialport.ui

RESOURCES += \
    res.qrc
