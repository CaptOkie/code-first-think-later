#include "ppidcontrol.h"
#include "splitsmallest.h"
#include "percentdistance.h"

PPIDControl::PPIDControl(Project& project)
    : project(project), form(*this), matcher(new PercentDistance()), grouper(new SplitSmallest(matcher)), worker(NULL)
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
    const QMap<int, Group*>& groups = project.getGroups();
    setMatches(groups);
    form.show(groups);
}

void PPIDControl::group()
{
    if (worker) {
        worker->deleteLater();
        worker = NULL;
    }
    worker = new GroupWorker(*grouper, project, this);
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
    const QMap<int, Group*>& gs = project.getGroups();
    setMatches(gs);
    form.update(gs);
}

void PPIDControl::setMatches(const QMap<int, Group*>& groups)
{
    for (QMap<int, Group*>::const_iterator git = groups.cbegin(); git != groups.cend(); ++git) {

        Group* group = git.value();
        int total = 0;
        int count = 0;
        for (QMap<int, Student*>::iterator sit = group->getStudents().begin(); sit != group->getStudents().end(); ++sit) {

            Student* student = sit.value();
            Group temp(*group);
            temp.getStudents().remove(student->getId());
            total += matcher->match(*student, temp);
            count += 1;
        }
        if (count) {
            group->setMatch(total / count);
        }
    }
}
