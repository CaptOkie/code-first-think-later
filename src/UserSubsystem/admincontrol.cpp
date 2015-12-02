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
    QMap<QString, Project*> projects = admin->getProjects();
    QMap<QString, Project*>::const_iterator i = projects.constBegin();
    while (i != projects.constEnd())
    {
        QStringList list;
        const Project& p = **i;
        list.append(QString::number(p.getId()));
        list.append(i.value()->getName());
        list.append(QString::number(p.getMaxGroupSize()));
        list.append(QString::number(p.getMinGroupSize()));
        new QTreeWidgetItem(adminForm.getTreeWidget(), list);
        ++i;
    }
}

void AdminControl::editProject()
{

}

