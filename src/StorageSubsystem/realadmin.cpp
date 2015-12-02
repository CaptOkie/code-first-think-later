#include "realadmin.h"

RealAdmin::RealAdmin(int id, QString* name)
    : Admin(id, name), projects(NULL)
{ }

RealAdmin::~RealAdmin()
{ }

QMap<QString, Project*>& RealAdmin::getProjects()
{

}

const QMap<QString, Project*>& RealAdmin::getProjects() const
{
    return *projects;
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
    projects->remove(project.getName());
}

void RealAdmin::addProject(const Project& project)
{
//    projects->insert(project.getName(), project);
}
