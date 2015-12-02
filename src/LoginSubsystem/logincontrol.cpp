#include "logincontrol.h"

LoginControl::LoginControl()
{
}

LoginControl::~LoginControl()
{
}

bool LoginControl::start(QString id)
{
    UserControl* adminTest = factory.getUser(id, "admin");
    UserControl* studentTest = factory.getUser(id, "student");

    if (adminTest != NULL) {
        delete studentTest;
        delete adminTest;
        adminForm = new AdminForm();
        adminForm->setGeometry(
                    QStyle::alignedRect(
                        Qt::LeftToRight,
                        Qt::AlignCenter,
                        adminForm->size(),
                        qApp->desktop()->availableGeometry()
                    )
                );
        adminForm->show();
        return true;
    }

    else if (studentTest != NULL) {
        delete adminTest;
        delete studentTest;
        stuForm = new StudentForm();
        stuForm->setGeometry(
                    QStyle::alignedRect(
                        Qt::LeftToRight,
                        Qt::AlignCenter,
                        stuForm->size(),
                        qApp->desktop()->availableGeometry()
                    )
                );
        stuForm->show();
        return true;
    }

    else {
        return false;
    }
}
