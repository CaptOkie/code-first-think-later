#ifndef REALPROJECT_H
#define REALPROJECT_H

#include "project.h"

class RealProject : public Project
{
    public:
        RealProject(int id, QString* name, int minGroupSize, int maxGroupSize);
        ~RealProject();

        const QMap<int, Student*>& getStudents() const;
        const QMap<int, Group*>& getGroups() const;

        void setGroups(const QList<Group*>& groups);
        void setGroups(const QMap<int, Group*>& groups);

};

#endif // REALPROJECT_H
