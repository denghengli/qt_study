#-------------------------------------------------
#
# Project created by QtCreator 2020-08-23T18:19:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 01_newfirst
TEMPLATE = app


SOURCES += main.cpp\
        mywidget.cpp \
    mypushbutton.cpp

HEADERS  += mywidget.h \
    mypushbutton.h

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
