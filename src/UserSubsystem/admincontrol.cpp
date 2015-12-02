#include "admincontrol.h"

AdminControl::AdminControl(Admin* admin)
    :  adminForm(), admin(admin)
{ }

AdminControl::~AdminControl()
{
    if (admin) {
        delete admin;
    }
}

void AdminControl::start()
{
    adminForm.setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            adminForm.size(),
            qApp->desktop()->availableGeometry()
        )
    );
    //adminForm.setName(user->getName());
    adminForm.show();
}
