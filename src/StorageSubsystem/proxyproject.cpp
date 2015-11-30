#include "proxyproject.h"

ProxyProject::ProxyProject(int id, QString* name, int minGroupSize, int maxGroupSize, ProjectStorage* storage)
    : Project(id, name, minGroupSize, maxGroupSize), storage(storage),
      realProject(new RealProject(id, name, minGroupSize, maxGroupSize))
{ }

ProxyProject::~ProxyProject()
{
    if (realProject)
        delete realProject;

    if (storage)
        delete storage;
}
