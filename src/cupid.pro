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


SOURCES += main.cpp \
    loginform.cpp \
    helpdialog.cpp \
    user.cpp \
    student.cpp \
    admin.cpp \
    db/userstorage.cpp \
    db/adminstorage.cpp \
    db/studentstorage.cpp \
    db/questionstorage.cpp \
    db/projectstorage.cpp

HEADERS  += \
    loginform.h \
    helpdialog.h \
    user.h \
    student.h \
    admin.h \
    db/userstorage.h \
    db/adminstorage.h \
    db/studentstorage.h \
    db/questionstorage.h \
    db/projectstorage.h

FORMS    += \
    loginform.ui \
    helpdialog.ui

RESOURCES += \
    resources/images.qrc
