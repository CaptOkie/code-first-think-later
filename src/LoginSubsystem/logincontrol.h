#ifndef LOGINCONTROL_H
#define LOGINCONTROL_H

#include <QString>
#include <QDesktopWidget>
#include <QApplication>
#include <QStyle>

#include "UserSubsystem/adminform.h"
#include "UserSubsystem/studentform.h"

class LoginControl
{
public:
    LoginControl();
    ~LoginControl();

    bool start(QString);

private:
    StudentForm* stuForm;
    AdminForm* adminForm;
};

#endif // LOGINCONTROL_H
