#include "realadmin.h"
#include "realproject.h"

RealAdmin::RealAdmin(int id, QString* name)
    : Admin(id, name), projects(NULL)
{ }

RealAdmin::~RealAdmin()
{ }

QMap<QString, Project*>& RealAdmin::getProjects()
{

}

void RealAdmin::setProjects(QMap<QString, Project*>* projects)
{
    this->projects = projects;
}

const QMap<QString, Project*>& RealAdmin::getProjects() const
{
    return *projects;
}

bool RealAdmin::hasProjects() const
{
    return projects != NULL;
}

Project* RealAdmin::deleteProject(const Project& project)
{
    return projects->take(project.getName());
}

bool RealAdmin::addProject(Project& project)
{
    projects->insert(project.getName(), &project);
    return true;
}

