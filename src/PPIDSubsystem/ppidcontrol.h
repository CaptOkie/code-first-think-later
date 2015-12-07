#ifndef PPIDCONTROL_H
#define PPIDCONTROL_H

#include "StorageSubsystem/project.h"
#include "ppidform.h"
#include "grouper.h"
#include "groupworker.h"
#include <QObject>

class PPIDControl : public QObject
{
    Q_OBJECT

    public:
        PPIDControl(Project& project);
        ~PPIDControl();

        void start();
        void group();

    private:
        Project& project;
        PPIDForm form;
        Matcher* matcher;
        Grouper* grouper;
        GroupWorker* worker;

        void setMatches(const QMap<int, Group*>& groups);

    private slots:
        void complete(QList<Group*>* groups);
};

#endif // PPIDCONTROL_H
