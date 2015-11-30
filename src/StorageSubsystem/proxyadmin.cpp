#include "proxyadmin.h"

ProxyAdmin::ProxyAdmin(int id, QString* name, AdminStorage* storage)
    : Admin(id, name), realAdmin(new RealAdmin(id, name)), storage(storage)
{ }

ProxyAdmin::~ProxyAdmin()
{
    if (realAdmin)
        delete realAdmin;

    if(storage)
        delete storage;
}

const QMap<QString, Project*>& ProxyAdmin::getProjects() const
{
    if (!(realAdmin->hasProjects())) {
        QMap<QString, Project*>* projects = storage->getProjects();
        realAdmin->setProjects(projects);
    }

    return realAdmin->getProjects();
}

void ProxyAdmin::deleteProject(const Project& project)
{

}

void ProxyAdmin::addProject(const Project& project)
{

}
