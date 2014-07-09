#-------------------------------------------------
#
# Project created by QtCreator 2014-07-08T11:37:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cannon
TEMPLATE = app


SOURCES += main.cpp\
        cannon.cpp \
    gun.cpp \
    ball.cpp

CONFIG += c++11

HEADERS  += cannon.h \
    gun.h \
    ball.h

FORMS    += cannon.ui
