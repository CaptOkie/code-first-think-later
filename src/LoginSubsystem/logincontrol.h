#ifndef LOGINCONTROL_H
#define LOGINCONTROL_H

#include <QString>
#include <QDesktopWidget>
#include <QApplication>
#include <QStyle>

#include "usercontrolfactory.h"
#include "loginform.h"

class LoginControl
{
public:
    LoginControl();
    ~LoginControl();

    bool studentLogin(QString);
    bool adminLogin(QString);
    void start();

private:
    AdminControl* adminControl;
    StudentControl* studentControl;
    LoginForm* loginForm;
    UserControlFactory factory;
};

#endif // LOGINCONTROL_H
