#include "ppidcontrol.h"
#include "ppidform.h"

PPIDControl::PPIDControl(Project& project)
    : project(project), form()
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
