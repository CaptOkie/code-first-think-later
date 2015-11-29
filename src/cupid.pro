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
    StorageSubsystem/admin.cpp \
    StorageSubsystem/user.cpp \
    StorageSubsystem/student.cpp \
    StorageSubsystem/adminstorage.cpp \
    StorageSubsystem/projectstorage.cpp \
    StorageSubsystem/questionstorage.cpp \
    StorageSubsystem/studentstorage.cpp \
    StorageSubsystem/userstorage.cpp

HEADERS  += \
    loginform.h \
    helpdialog.h \
    StorageSubsystem/admin.h \
    StorageSubsystem/user.h \
    StorageSubsystem/student.h \
    StorageSubsystem/adminstorage.h \
    StorageSubsystem/projectstorage.h \
    StorageSubsystem/questionstorage.h \
    StorageSubsystem/studentstorage.h \
    StorageSubsystem/userstorage.h

FORMS    += \
    loginform.ui \
    helpdialog.ui

RESOURCES += \
    resources/images.qrc
