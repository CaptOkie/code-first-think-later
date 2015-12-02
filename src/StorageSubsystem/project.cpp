#include "project.h"

Project::Project(int id, QString* name, int minGroupSize, int maxGroupSize)
    : id(id), name(name), minGroupSize(minGroupSize), maxGroupSize(maxGroupSize)
{ }

Project::Project(const Project& project)
    : id(project.getId()), name(new QString(project.getName())), minGroupSize(project.getMinGroupSize()),
      maxGroupSize(project.getMaxGroupSize())
{ }

Project::~Project()
{
    if (name)
        delete name;
}

int Project::getId() const
{
    return id;
}

const QString& Project::getName() const
{
    return *name;
}

int Project::getMinGroupSize() const
{
    return minGroupSize;
}

int Project::getMaxGroupSize() const
{
    return maxGroupSize;
}
