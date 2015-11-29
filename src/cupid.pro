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
    StorageSubsystem/admin.cpp \
    StorageSubsystem/user.cpp \
    StorageSubsystem/student.cpp \
    StorageSubsystem/adminstorage.cpp \
    StorageSubsystem/projectstorage.cpp \
    StorageSubsystem/questionstorage.cpp \
    StorageSubsystem/studentstorage.cpp \
    StorageSubsystem/userstorage.cpp \
    LoginSubsystem/loginform.cpp \
    LoginSubsystem/helpdialog.cpp \
    StorageSubsystem/question.cpp \
    StorageSubsystem/project.cpp \
    ProfileSubsystem/profilecontrol.cpp \
    LoginSubsystem/logincontrol.cpp \
    LoginSubsystem/usercontrolfactory.cpp \
    UserSubsystem/studentcontrol.cpp \
    UserSubsystem/admincontrol.cpp \
    UserSubsystem/usercontrol.cpp \
    ProjectSubsystem/projectcontrol.cpp \
    PPIDSubsystem/percentdistance.cpp \
    PPIDSubsystem/matcher.cpp \
    PPIDSubsystem/splitsmallest.cpp \
    PPIDSubsystem/grouper.cpp \
    PPIDSubsystem/ppidcontrol.cpp \
    UserSubsystem/studentform.cpp \
    UserSubsystem/adminform.cpp \
    ProjectSubsystem/projectform.cpp \
    StorageSubsystem/answer.cpp \
    StorageSubsystem/group.cpp \
    exceptions/notadminexception.cpp \
    StorageSubsystem/realadmin.cpp

HEADERS  += \
    StorageSubsystem/admin.h \
    StorageSubsystem/user.h \
    StorageSubsystem/student.h \
    StorageSubsystem/adminstorage.h \
    StorageSubsystem/projectstorage.h \
    StorageSubsystem/questionstorage.h \
    StorageSubsystem/studentstorage.h \
    StorageSubsystem/userstorage.h \
    LoginSubsystem/loginform.h \
    LoginSubsystem/helpdialog.h \
    StorageSubsystem/question.h \
    StorageSubsystem/project.h \
    ProfileSubsystem/profilecontrol.h \
    LoginSubsystem/logincontrol.h \
    LoginSubsystem/usercontrolfactory.h \
    UserSubsystem/studentcontrol.h \
    UserSubsystem/admincontrol.h \
    UserSubsystem/usercontrol.h \
    ProjectSubsystem/projectcontrol.h \
    PPIDSubsystem/percentdistance.h \
    PPIDSubsystem/matcher.h \
    PPIDSubsystem/splitsmallest.h \
    PPIDSubsystem/grouper.h \
    PPIDSubsystem/ppidcontrol.h \
    UserSubsystem/studentform.h \
    UserSubsystem/adminform.h \
    ProjectSubsystem/projectform.h \
    StorageSubsystem/answer.h \
    StorageSubsystem/group.h \
    StorageSubsystem/storage.h
    StorageSubsystem/realadmin.h

FORMS    += \
    LoginSubsystem/loginform.ui \
    LoginSubsystem/helpdialog.ui \
    UserSubsystem/studentform.ui \
    UserSubsystem/adminform.ui \
    ProjectSubsystem/projectform.ui

RESOURCES += \
    resources/images.qrc
