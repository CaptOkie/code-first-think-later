#include "logincontrol.h"

#include "usercontrolfactory.h"

LoginControl::LoginControl()
{
}

void LoginControl::start(QString id)
{
    UserControlFactory factory;
    User user = factory.getUser(id);
}
