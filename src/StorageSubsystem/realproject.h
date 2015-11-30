#ifndef REALPROJECT_H
#define REALPROJECT_H

#include "project.h"

class RealProject : public Project
{
    public:
        RealProject();
        ~RealProject();

        int getId() const;
        const QString& getName() const;
        int getMaxGroupSize() const;
        int getMinGroupSize() const;

        const QMap<int, Student*>& getStudents() const;
        const QMap<int, Group*>& getGroups() const;

        void setGroups(const QList<Group*>& groups);
        void setGroups(const QMap<int, Group*>& groups);

};

#endif // REALPROJECT_H
