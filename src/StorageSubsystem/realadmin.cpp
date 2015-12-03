#include "realadmin.h"
#include "realproject.h"

RealAdmin::RealAdmin(int id, QString* name)
    : id(id), name(name), projects(NULL)
{ }

RealAdmin::~RealAdmin()
{
    if (projects) {
        for (QMap<QString, Project*>::iterator it = projects->begin(); it != projects->end(); ++it)
        {
            Project* project = it.value();
            delete project;
        }

        delete projects;
    }
    if (name) {
        delete name;
    }
}

int RealAdmin::getId() const
{
    return id;
}

const QString& RealAdmin::getName() const
{
    return *name;
}

QMap<QString, Project*>& RealAdmin::getProjects()
{
    return *projects;
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

