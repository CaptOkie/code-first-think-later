#ifndef PROJECT_H
#define PROJECT_H

#include "groupsize.h"
#include <QString>

class Project
{
    public:
        Project(QString&, GroupSize&);
        Project(const Project&);

        const GroupSize& getGroupSize() const;
        GroupSize& getGroupSize();
        const QString& getName() const;
        QString& getName();

    private:
        QString* name;
        GroupSize* groupSize;
};

#endif // PROJECT_H
