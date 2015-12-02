#ifndef LOGINCONTROL_H
#define LOGINCONTROL_H

#include "usercontrolfactory.h"
#include "loginform.h"

class LoginControl
{
public:
    LoginControl();
    ~LoginControl();

    bool studentLogin(int id);
    bool adminLogin(int id);
    void start();

private:
    LoginForm loginForm;
    UserControlFactory factory;
    UserControl* userControl;

    bool login(int id, UserControlFactory::Type type);
};

#endif // LOGINCONTROL_H
