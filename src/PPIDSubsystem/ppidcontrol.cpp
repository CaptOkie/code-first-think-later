#include "ppidcontrol.h"
#include "grouper.h"
#include "splitsmallest.h"
#include "percentdistance.h"

PPIDControl::PPIDControl(Project& project)
    : project(project), form(*this), grouper(new SplitSmallest(new PercentDistance()))
{ }

PPIDControl::~PPIDControl()
{
    if (grouper) {
        delete grouper;
    }
}

void PPIDControl::start()
{
    form.show(project.getGroups());
}

void PPIDControl::group()
{
    QList<Group*>* groups = grouper->group(project);
    if (groups) {
        project.setGroups(*groups);
        delete groups;
    }
    form.update(project.getGroups());
}
