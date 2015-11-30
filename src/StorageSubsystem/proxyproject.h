#ifndef PROXYPROJECT_H
#define PROXYPROJECT_H

#include "project.h"
#include "realproject.h"

class ProxyProject
{
    public:
        ProxyProject();
        ~ProxyProject();

        int getId() const;
        const QString& getName() const;
        int getMaxGroupSize() const;
        int getMinGroupSize() const;

        virtual const QMap<int, Student>& getStudents() const;
        virtual const QMap<int, Group>& getGroups() const;

        virtual void setGroups(const QList<Group>& groups);
        virtual void setGroups(const QMap<int, Group>& groups);


    private:
        RealProject* realProject;
};

#endif // PROXYPROJECT_H
