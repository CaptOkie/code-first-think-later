#include "logincontrol.h"

LoginControl::LoginControl()
{
}

LoginControl::~LoginControl()
{
}

bool LoginControl::studentLogin(QString id)
{
    UserControl* adminControl = factory.getUser(id, "admin");
    UserControl* studentControl = factory.getUser(id, "student");

    if (adminControl != NULL) {
        delete studentControl;
        adminControl->start();
        return true;
    }

    else if (studentControl != NULL) {
        delete adminControl;
        studentControl->start();
        return true;
    }

    else {
        delete adminControl;
        delete studentControl;
        return false;
    }
}

bool LoginControl::adminLogin(QString id)
{
    UserControl* adminControl = factory.getUser(id, "admin");
    UserControl* studentControl = factory.getUser(id, "student");

    if (adminControl != NULL) {
        delete studentControl;
        adminControl->start();
        return true;
    }

    else if (studentControl != NULL) {
        delete adminControl;
        studentControl->start();
        return true;
    }

    else {
        delete adminControl;
        delete studentControl;
        return false;
    }
}

void LoginControl::start()
{
    loginForm = new LoginForm();
        loginForm->setGeometry(
            QStyle::alignedRect(
                Qt::LeftToRight,
                Qt::AlignCenter,
                loginForm->size(),
                qApp->desktop()->availableGeometry()
            )
        );
    loginForm->show();
}
