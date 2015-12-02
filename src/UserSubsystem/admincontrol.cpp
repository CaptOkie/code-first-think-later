#include "admincontrol.h"

AdminControl::AdminControl(Admin* admin)
    : adminForm(), admin(admin)//, storage()
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
    adminForm.show();
}

void AdminControl::loadProjects()
{
    adminForm.getTreeWidget()->clear();
    /*QMap<QString, Project*>* projects = storage.getProjects();
    QMap<QString, Project*>::const_iterator i = projects->constBegin();
    while (i != projects->constEnd())
    {
        Project project = i.key();
        QStringList list;
        list.append(project.getId());
        list.append(project.getName());
        list.append(project.getMaxGroupSize());
        list.append(project.getMinGroupSize());
        new QTreeWidgetItem(adminForm.getTreeWidget(), list);
        ++i;
    }
    */
}

void AdminControl::editProject()
{

}

