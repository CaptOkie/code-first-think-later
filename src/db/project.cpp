#include "project.h"

Project::Project(const QString& name, const GroupSize& groupSize)
    : name(name), groupSize(groupSize)
{
}

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

void Project::setName(const QString& name)
{
    this->name = name;
}
