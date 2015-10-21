#-------------------------------------------------
#
# Project created by QtCreator 2015-10-17T22:30:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
        ui/mainwindow.cpp\
    ui/stulogindialog.cpp\
    ui/adminlogindialog.cpp

HEADERS  += ui/mainwindow.h\
    ui/stulogindialog.h\
    ui/adminlogindialog.h

FORMS    += ui/mainwindow.ui\
    ui/stulogindialog.ui\
    ui/adminlogindialog.ui

RESOURCES += \
    resources/images.qrc
