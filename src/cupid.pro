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
    StorageSubsystem/realadmin.cpp \
    StorageSubsystem/storageinitializer.cpp \
    StorageSubsystem/proxyadmin.cpp \
    StorageSubsystem/realstudent.cpp \
    StorageSubsystem/proxystudent.cpp \
    PPIDSubsystem/ppidform.cpp \
    PPIDSubsystem/groupwidget.cpp \
    StorageSubsystem/realproject.cpp \
    StorageSubsystem/proxyproject.cpp \
    LoginSubsystem/errordialog.cpp \
    UserSubsystem/logoutdialog.cpp \
    ProfileSubsystem/profileform.cpp \
    LoginSubsystem/newaccountdialog.cpp \
    StorageSubsystem/realquestion.cpp \
    StorageSubsystem/indicator.cpp \
    StorageSubsystem/proxyquestion.cpp \
    ProfileSubsystem/questionwidget.cpp \
    ProfileSubsystem/questionswidget.cpp \
    UserSubsystem/confirmationdialog.cpp \
    ProjectSubsystem/perrordialog.cpp

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
    StorageSubsystem/storage.h \
    StorageSubsystem/storageinitializer.h \
    StorageSubsystem/proxyadmin.h \
    StorageSubsystem/realstudent.h \
    StorageSubsystem/realadmin.h \
    StorageSubsystem/proxystudent.h \
    PPIDSubsystem/ppidform.h \
    PPIDSubsystem/groupwidget.h \
    StorageSubsystem/realproject.h \
    StorageSubsystem/proxyproject.h \
    LoginSubsystem/errordialog.h \
    UserSubsystem/logoutdialog.h \
    ProfileSubsystem/profileform.h \
    LoginSubsystem/newaccountdialog.h \
    StorageSubsystem/realquestion.h \
    StorageSubsystem/indicator.h \
    StorageSubsystem/proxyquestion.h \
    ProfileSubsystem/questionwidget.h \
    ProfileSubsystem/questionswidget.h \
    UserSubsystem/confirmationdialog.h \
    ProjectSubsystem/perrordialog.h

FORMS    += \
    LoginSubsystem/loginform.ui \
    LoginSubsystem/helpdialog.ui \
    UserSubsystem/studentform.ui \
    UserSubsystem/adminform.ui \
    ProjectSubsystem/projectform.ui \
    PPIDSubsystem/ppidform.ui \
    LoginSubsystem/errordialog.ui \
    UserSubsystem/logoutdialog.ui \
    ProfileSubsystem/profileform.ui \
    LoginSubsystem/newaccountdialog.ui \
    ProfileSubsystem/questionswidget.ui \
    UserSubsystem/confirmationdialog.ui \
    ProjectSubsystem/perrordialog.ui

RESOURCES += \
    resources/images.qrc
