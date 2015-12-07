#include "groupworker.h"

GroupWorker::GroupWorker(Grouper& grouper, const Project& project, QObject* parent)
    : QThread(parent), grouper(grouper), project(project)
{ }

GroupWorker::~GroupWorker()
{ }

void GroupWorker::run()
{
    QList<Group*>* groups = grouper.group(project);
    emit complete(groups);
}
