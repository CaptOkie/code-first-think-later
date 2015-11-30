#include "project.h"

Project::Project(int id, QString* name, int minGroupSize, int maxGroupSize)
    : id(id), name(name), minGroupSize(minGroupSize), maxGroupSize(maxGroupSize)
{ }

Project::~Project()
{
    if (name)
        delete name;
}
