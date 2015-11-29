#include "logincontrol.h"

#include "usercontrolfactory.h"

LoginControl::LoginControl()
{
}

void LoginControl::start(QString id)
{
    UserControlFactory factory;
    UserControl* adminTest = factory.getUser(id, "admin");
    UserControl* studentTest = factory.getUser(id, "student");

    if (adminTest != NULL) {

    }

    else if (studentTest != NULL) {

    }
}
