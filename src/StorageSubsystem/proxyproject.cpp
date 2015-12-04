#include "proxyproject.h"

ProxyProject::ProxyProject(int id, QString* name, int minGroupSize, int maxGroupSize, ProjectStorage* storage)
    : hasLoaded(false), realProject(new RealProject(id, name, minGroupSize, maxGroupSize)), storage(storage)
{ }

ProxyProject::ProxyProject(const Project& other, ProjectStorage* storage)
    : realProject(new RealProject(other.getId(), new QString(other.getName()), other.getMinGroupSize(),
                                  other.getMaxGroupSize())),
      storage(storage)
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
    if (realProject->getStudents().isEmpty())
    {
        QMap<int, Group*>* groups = storage->getGroups(*this);
        QMap<int, Student*>* students = new QMap<int, Student*>();
        for (QMap<int, Group*>::iterator it = groups->begin(); it != groups->end(); ++it)
        {
            students->unite(it.value()->getStudents());
        }
        realProject->setGroups(groups);
        realProject->setStudents(students);
    }

    return realProject->getStudents();
}

const QMap<int, Group*>& ProxyProject::getGroups() const
{
    if (realProject->getGroups().isEmpty())
    {
        QMap<int, Group*>* groups = storage->getGroups(*this);
        QMap<int, Student*>* students = new QMap<int, Student*>();
        for (QMap<int, Group*>::iterator it = groups->begin(); it != groups->end(); ++it)
        {
            students->unite(it.value()->getStudents());
        }
        realProject->setGroups(groups);
        realProject->setStudents(students);
    }

    return realProject->getGroups();
}

void ProxyProject::setGroups(QList<Group*>& groups)
{

}

void ProxyProject::setGroups(QMap<int, Group*>* groups)
{

}
