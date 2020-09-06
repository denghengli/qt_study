#-------------------------------------------------
#
# Project created by QtCreator 2020-08-29T16:21:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 11_smallWidget
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    smallwidget.cpp

HEADERS  += widget.h \
    smallwidget.h

FORMS    += widget.ui \
    smallwidget.ui

CONFIG += c++11
