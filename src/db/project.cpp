#include "project.h"

Project::Project(QString& name, GroupSize& groupSize)
    : name(name), groupSize(groupSize)
{ }

Project::Project(Project& copy)
    : name(copy.getName()), groupSize(copy.getGroupSize())
{ }

const GroupSize& Project::getGroupSize() const
{
    return groupSize;
}

GroupSize& Project::getGroupSize()
{
    return groupSize;
}

const QString& Project::getName() const
{
    return name;
}

QString& Project::getName()
{
    return name;
}

