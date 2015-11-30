#include "proxyproject.h"

ProxyProject::ProxyProject(ProjectStorage* storage)
    : realpath(NULL), storage(storage)
{ }

ProxyProject::~ProxyProject()
{
    if (realProject)
        delete realProject;

    if (storage)
        delete storage;
}
