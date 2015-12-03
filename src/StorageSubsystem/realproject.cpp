#include "realproject.h"

RealProject::RealProject(int id, QString* name, int minGroupSize, int maxGroupSize)
    : id(id), name(name), minGroupSize(minGroupSize), maxGroupSize(maxGroupSize)
{ }

RealProject::~RealProject()
{
    if (name)
        delete name;
}

int RealProject::getId() const
{
    return id;
}

const QString& RealProject::getName() const
{
    return *name;
}

int RealProject::getMinGroupSize() const
{
    return minGroupSize;
}

int RealProject::getMaxGroupSize() const
{
    return maxGroupSize;
}

const QMap<int, Student*>& RealProject::getStudents() const
{

}

const QMap<int, Group*>& RealProject::getGroups() const
{

}

void RealProject::setGroups(const QList<Group*>& groups)
{

}

void RealProject::setGroups(const QMap<int, Group*>* groups)
{

}
