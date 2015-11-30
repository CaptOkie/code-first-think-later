#include "logincontrol.h"

#include "usercontrolfactory.h"
#include "UserSubsystem/adminform.h"
#include "UserSubsystem/studentform.h"

LoginControl::LoginControl()
{
}

bool LoginControl::start(QString id)
{
    UserControlFactory factory;
    UserControl* adminTest = factory.getUser(id, "admin");
    UserControl* studentTest = factory.getUser(id, "student");

    if (adminTest != NULL) {
        delete studentTest;
        AdminForm form;
        form.show();
        return true;
    }

    else if (studentTest != NULL) {
        delete adminTest;
        StudentForm form;
        form.show();
        return true;
    }
    return false;
}
