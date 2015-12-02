#include "logincontrol.h"
#include "ui_loginform.h"

LoginControl::LoginControl()
    : loginForm(*this), factory(), userControl(NULL)
{ }

LoginControl::~LoginControl()
{
    if (userControl) {
        delete userControl;
    }
}

bool LoginControl::studentLogin(int id)
{
    return login(id, UserControlFactory::StudentType);
}

bool LoginControl::adminLogin(int id)
{
    return login(id, UserControlFactory::AdminType);
}

bool LoginControl::login(int id, UserControlFactory::Type type)
{
    if (userControl) {
        delete userControl;
        userControl = NULL;
    }
    userControl = factory.getUser(id, type);

    if (userControl) {
        userControl->start();
        return true;
    }
    return false;
}

void LoginControl::start()
{
    loginForm.show();
}
