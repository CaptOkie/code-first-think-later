#include "project.h"

Project::Project(QString* name, GroupSize* groupSize)
    : name(name), groupSize(groupSize)
{ }

Project::Project(const Project& copy)
    : name(copy.name), groupSize(copy.groupSize)
{ }

Project::~Project()
{
    delete name;
    delete groupSize;
}

const GroupSize& Project::getGroupSize() const
{
    return *groupSize;
}

GroupSize& Project::getGroupSize()
{
    return *groupSize;
}

const QString& Project::getName() const
{
    return *name;
}

QString& Project::getName()
{
    return *name;
}
