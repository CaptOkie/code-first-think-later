#include "proxyproject.h"

ProxyProject::ProxyProject(int id, QString* name, int minGroupSize, int maxGroupSize, ProjectStorage* storage)
    : Project(id, name, minGroupSize, maxGroupSize), realpath(NULL), storage(storage)
{ }

ProxyProject::~ProxyProject()
{
    if (realProject)
        delete realProject;

    if (storage)
        delete storage;
}
