#include "ppidcontrol.h"
#include "splitsmallest.h"
#include "percentdistance.h"

PPIDControl::PPIDControl(Project& project)
    : project(project), form(*this), grouper(new SplitSmallest(new PercentDistance())), worker(NULL)
{ }

PPIDControl::~PPIDControl()
{
    if (grouper) {
        delete grouper;
    }

    if (worker) {
        worker->deleteLater();
    }
}

void PPIDControl::start()
{
    form.show(project.getGroups());
}

void PPIDControl::group()
{
    if (worker) {
        worker->deleteLater();
        worker = NULL;
    }
    worker = new GroupWorker(*grouper, project);
    connect(worker, &GroupWorker::complete, this, &PPIDControl::complete);
    worker->start();
}

void PPIDControl::complete(QList<Group*>* groups)
{
    if (groups) {
        if (!(project.setGroups(*groups))) {
            for (QList<Group*>::iterator it = groups->begin(); it != groups->end(); ++it) {
                Group* group = *it;
                delete group;
            }
        }
        delete groups;
    }
    form.update(project.getGroups());
}
