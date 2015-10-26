#-------------------------------------------------
#
# Project created by QtCreator 2015-10-17T22:30:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets\
    sql

TARGET = cupid
TEMPLATE = app


SOURCES += main.cpp\
    ui/mainwindow.cpp\
    ui/stulogindialog.cpp\
    ui/adminlogindialog.cpp \
    ui/errordialog.cpp \
    ui/loginwidget.cpp
    db/storage.cpp

HEADERS  += ui/mainwindow.h\
    ui/stulogindialog.h\
    ui/adminlogindialog.h \
    ui/errordialog.h \
    ui/loginwidget.h \
    db/storage.h

FORMS    += ui/mainwindow.ui\
    ui/stulogindialog.ui\
    ui/adminlogindialog.ui \
    ui/errordialog.ui \
    ui/loginwidget.ui

RESOURCES += \
    resources/images.qrc
