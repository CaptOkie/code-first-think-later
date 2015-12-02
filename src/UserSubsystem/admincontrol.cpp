#include "admincontrol.h"

AdminControl::AdminControl()
{
}

AdminControl::~AdminControl()
{

}

void AdminControl::start()
{
    adminForm = new AdminForm();
        adminForm->setGeometry(
            QStyle::alignedRect(
                Qt::LeftToRight,
                Qt::AlignCenter,
                adminForm->size(),
                qApp->desktop()->availableGeometry()
            )
        );
        //adminForm->setName(user->getName());
        adminForm->show();
}
