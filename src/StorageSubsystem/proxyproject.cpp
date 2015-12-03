#include "proxyproject.h"

ProxyProject::ProxyProject(int id, QString* name, int minGroupSize, int maxGroupSize, ProjectStorage* storage)
    : realProject(new RealProject(id, name, minGroupSize, maxGroupSize)), storage(storage)
{ }

ProxyProject::ProxyProject(const ProxyProject& other)
    : ProxyProject(other, new ProjectStorage(*(other.storage)))
{ }

ProxyProject::ProxyProject(const Project& other, ProjectStorage* storage)
    : ProxyProject(other.getId(), new QString(other.getName()), other.getMinGroupSize(), other.getMaxGroupSize(), storage)
{ }

ProxyProject::~ProxyProject()
{
    if (realProject)
        delete realProject;
    if (storage)
        delete storage;
}

int ProxyProject::getId() const
{
    return realProject->getId();
}

const QString& ProxyProject::getName() const
{
    return realProject->getName();
}

int ProxyProject::getMinGroupSize() const
{
    return realProject->getMinGroupSize();
}

int ProxyProject::getMaxGroupSize() const
{
    return realProject->getMaxGroupSize();
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
