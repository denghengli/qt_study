#-------------------------------------------------
#
# Project created by QtCreator 2020-08-30T10:46:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 13_QPainter
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

RESOURCES += \
    ../image.qrc

CONFIG += c++11
