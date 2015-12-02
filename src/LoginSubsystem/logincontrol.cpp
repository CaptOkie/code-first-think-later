#include "logincontrol.h"
#include "ui_loginform.h"

LoginControl::LoginControl()
{
}

LoginControl::~LoginControl()
{
}

bool LoginControl::studentLogin()
{
    UserControl* studentControl = factory.getUser(loginForm->ui->userIDInput->text(), "student");

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

bool LoginControl::adminLogin()
{
    UserControl* adminControl = factory.getUser(loginForm->ui->userIDInput->text(), "admin");

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
