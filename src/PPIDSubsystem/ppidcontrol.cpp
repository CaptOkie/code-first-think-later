#include "ppidcontrol.h"

PPIDControl::PPIDControl(Project& project)
    : project(project), form(*this)
{ }

PPIDControl::~PPIDControl()
{ }

void PPIDControl::start()
{
    form.show(project.getGroups());
}

void PPIDControl::group()
{
    form.update(project.getGroups()); // TODO
}
