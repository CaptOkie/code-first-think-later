#ifndef PROJECT_H
#define PROJECT_H

#include "groupsize.h"
#include <QString>

class Project
{
    public:
        Project(const QString&, const GroupSize&);
        Project(const Project&);

        const GroupSize& getGroupSize() const;
        GroupSize& getGroupSize();
        const QString& getName() const;
        void setName(const QString&);

    private:
        QString name;
        GroupSize groupSize;
};

#endif // PROJECT_H
