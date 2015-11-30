#include "realadmin.h"

RealAdmin::RealAdmin(int id, QString* name)
    : Admin(id, name), projects(NULL)
{ }

RealAdmin::~RealAdmin()
{ }

const QMap<QString, Project*>& RealAdmin::getProjects() const
{

}

bool RealAdmin::hasProjects() const
{
    return projects != NULL;
}

void RealAdmin::setProjects(QMap<QString, Project*>* projects)
{
    this->projects = projects;
}

void RealAdmin::deleteProject(const Project& project)
{

}

void RealAdmin::addProject(const Project& project)
{

}
