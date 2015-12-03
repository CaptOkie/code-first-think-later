#include "admincontrol.h"

AdminControl::AdminControl(Admin* admin)
    : adminForm(*this), admin(admin)
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
    adminForm.setName(admin->getName());
    loadProjects();
}

void AdminControl::loadProjects()
{
    QMap<QString, Project*>& projects = admin->getProjects();
    adminForm.show(projects);
}

void AdminControl::editProject()
{

}

