#ifndef GROUPWORKER_H
#define GROUPWORKER_H

#include <QObject>
#include <QThread>
#include "StorageSubsystem/project.h"
#include "grouper.h"

class GroupWorker : public QThread
{
    Q_OBJECT

    public:
        GroupWorker(Grouper& grouper, const Project& project, QObject* parent = 0);
        ~GroupWorker();

    protected:
        void run();

    private:
        Grouper& grouper;
        const Project& project;

    signals:
        void complete(QList<Group*>* groups);
};

#endif // GROUPWORKER_H
