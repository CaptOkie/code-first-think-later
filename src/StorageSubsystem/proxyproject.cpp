#include "proxyproject.h"

ProxyProject::ProxyProject()
    : realpath(NULL)
{ }

ProxyProject::~ProxyProject()
{
    if (realProject)
        delete realProject;
}
