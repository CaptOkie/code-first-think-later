#ifndef LOGINCONTROL_H
#define LOGINCONTROL_H

#include <QString>
#include <QDesktopWidget>
#include <QApplication>
#include <QStyle>

#include "UserSubsystem/adminform.h"
#include "UserSubsystem/studentform.h"
#include "usercontrolfactory.h"

class LoginControl
{
public:
    LoginControl();
    ~LoginControl();

    bool start(QString);

private:
    StudentForm* stuForm;
    AdminForm* adminForm;
    UserControlFactory factory;
};

#endif // LOGINCONTROL_H
