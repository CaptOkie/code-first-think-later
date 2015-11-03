#include "project.h"

Project::Project(QString* name, GroupSize* groupSize)
    : name(name), groupSize(groupSize)
{ }

Project::Project(const QString& name, const GroupSize& groupSize)
    : name(new QString(name)), groupSize(new GroupSize(groupSize))
{ }

Project::Project(const Project& copy)
    : name(new QString(copy.getName())), groupSize(new GroupSize(copy.getGroupSize()))
{ }

Project::~Project()
{
    delete name;
    delete groupSize;
}

const QString& Project::getName() const
{
    return *name;
}

const GroupSize& Project::getGroupSize() const
{
    return *groupSize;
}
