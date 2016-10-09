#-------------------------------------------------
#
# Project created by QtCreator 2016-08-05T15:53:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = blackandwhite
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    Board.cpp \
    Move.cpp

HEADERS  += widget.h \
    Board.h \
    Move.h

FORMS    += widget.ui

RC_FILE += qt.rc
