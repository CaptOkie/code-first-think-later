#include "proxyproject.h"

ProxyProject::ProxyProject(int id, QString* name, int minGroupSize, int maxGroupSize, ProjectStorage* storage)
    : hasLoaded(new Indicator(false)), realProject(new RealProject(id, name, minGroupSize, maxGroupSize)),
      storage(storage)
{ }

ProxyProject::ProxyProject(const Project& other, ProjectStorage* storage)
    : hasLoaded(new Indicator(false)),
      realProject(new RealProject(other.getId(), new QString(other.getName()), other.getMinGroupSize(),
                                  other.getMaxGroupSize())),
      storage(storage)
{ }

ProxyProject::~ProxyProject()
{
    if (hasLoaded)
        delete hasLoaded;
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

bool ProxyProject::setName(QString *newName)
{
    if (storage->updateProject(*realProject))
        return realProject->setName(newName);
    return false;
}

bool ProxyProject::setMinGroupSize(int newMinGroupSize)
{
    if (storage->updateProject(*realProject))
        return realProject->setMinGroupSize(newMinGroupSize);
    return false;
}

bool ProxyProject::setMaxGroupSize(int newMaxGroupSize)
{
    if (storage->updateProject(*realProject))
        return realProject->setMaxGroupSize(newMaxGroupSize);
    return false;
}

const QMap<int, Student*>& ProxyProject::getStudents() const
{
    if (!(hasLoaded->getValue()))
    {
        QMap<int, Group*>* groups = storage->getGroups(*this);
        QMap<int, Student*>* students = new QMap<int, Student*>();
        for (QMap<int, Group*>::iterator it = groups->begin(); it != groups->end(); ++it)
        {
            students->unite(it.value()->getStudents());
        }
        realProject->setGroups(groups);
        realProject->setStudents(students);
        hasLoaded->toggleValue();
    }

    return realProject->getStudents();
}

const QMap<int, Group*>& ProxyProject::getGroups() const
{
    if (!(hasLoaded->getValue()))
    {
        QMap<int, Group*>* groups = storage->getGroups(*this);
        QMap<int, Student*>* students = new QMap<int, Student*>();
        for (QMap<int, Group*>::iterator it = groups->begin(); it != groups->end(); ++it)
        {
            students->unite(it.value()->getStudents());
        }
        realProject->setGroups(groups);
        realProject->setStudents(students);
        hasLoaded->toggleValue();
    }

    return realProject->getGroups();
}

bool ProxyProject::setGroups(QList<Group*>& groups)
{
    QMap<int, Group*>* groupsMap = storage->setGroups(*realProject, groups);
    if (groupsMap)
    {
        return realProject->setGroups(groupsMap);
    }
    return false;
}

bool ProxyProject::setGroups(QMap<int, Group*>* groups)
{
    if (realProject->setGroups(groups))
        return realProject->setGroups(groups);
    return false;
}
