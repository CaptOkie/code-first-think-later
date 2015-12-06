#include "proxyadmin.h"

ProxyAdmin::ProxyAdmin(int id, QString* name, AdminStorage* storage)
    : loadedProjects(new Indicator(false)), realAdmin(new RealAdmin(id, name)), storage(storage)
{ }

ProxyAdmin::~ProxyAdmin()
{
    if (realAdmin)
        delete realAdmin;
    if (storage)
        delete storage;
}

int ProxyAdmin::getId() const
{
    return realAdmin->getId();
}

const QString& ProxyAdmin::getName() const
{
    return realAdmin->getName();
}

QMap<QString, Project*>& ProxyAdmin::getProjects()
{
    if (!(loadedProjects->getValue())) {
        QMap<QString, Project*>* projects = storage->getProjects();
        realAdmin->setProjects(projects);
        loadedProjects->toggleValue();
    }

    return realAdmin->getProjects();
}

const QMap<QString, Project*>& ProxyAdmin::getProjects() const
{
    if (!(loadedProjects->getValue())) {
        QMap<QString, Project*>* projects = storage->getProjects();
        realAdmin->setProjects(projects);
        loadedProjects->toggleValue();
    }

    return realAdmin->getProjects();
}

Project* ProxyAdmin::deleteProject(const Project& project)
{
    if (storage->deleteProject(project))
        return realAdmin->deleteProject(project);
    return NULL;
}

bool ProxyAdmin::addProject(Project& project)
{
    Project* newProject = storage->addProject(project);
    if (newProject)
        return realAdmin->addProject(*newProject);
    return false;
}
