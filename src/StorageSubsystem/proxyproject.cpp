#include "proxyproject.h"

ProxyProject::ProxyProject(int id, QString* name, int minGroupSize, int maxGroupSize, ProjectStorage* storage)
    : Project(id, name, minGroupSize, maxGroupSize), storage(storage),
      realProject(new RealProject(id, name, minGroupSize, maxGroupSize))
{ }

ProxyProject::ProxyProject(const ProxyProject& other)
    : ProxyProject(other, new ProjectStorage(*(other.storage)))
{ }

ProxyProject::ProxyProject(const Project& project, ProjectStorage* storage)
    : Project(project), storage(storage)
{ }

ProxyProject::~ProxyProject()
{
    if (realProject)
        delete realProject;

    if (storage)
        delete storage;
}

const QMap<int, Student*>& ProxyProject::getStudents() const
{

}

const QMap<int, Group*>& ProxyProject::getGroups() const
{

}

void ProxyProject::setGroups(const QList<Group*>& groups)
{

}
