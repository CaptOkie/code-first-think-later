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
    ui/errordialog.cpp \
    ui/loginwidget.cpp \
    db/storage.cpp \
    ui/adminhomewidget.cpp \
    ui/projectdetailsdialog.cpp \
    ui/studenthomewidget.cpp \
    db/project.cpp \
    db/groupsize.cpp \
    db/user.cpp

HEADERS  += ui/mainwindow.h\
    ui/errordialog.h \
    ui/loginwidget.h \
    db/storage.h \
    ui/adminhomewidget.h \
    ui/projectdetailsdialog.h \
    ui/studenthomewidget.h \
    db/project.h \
    db/groupsize.h \
    db/user.h

FORMS    += ui/mainwindow.ui\
    ui/errordialog.ui \
    ui/loginwidget.ui \
    ui/adminhomewidget.ui \
    ui/projectdetailsdialog.ui \
    ui/studenthomewidget.ui

RESOURCES += \
    resources/images.qrc
