#ifndef PROXYPROJECT_H
#define PROXYPROJECT_H

#include "project.h"
#include "realproject.h"
#include "projectstorage.h"

class ProxyProject : public Project
{
    public:
        ProxyProject(int id, QString* name, int minGroupSize, int maxGroupSize, ProjectStorage* storage);
        ProxyProject(const ProxyProject& other);
        ProxyProject(const Project& project, ProjectStorage* storage);
        ~ProxyProject();

        virtual const QMap<int, Student*>& getStudents() const;
        virtual const QMap<int, Group*>& getGroups() const;

        virtual void setGroups(const QList<Group*>& groups);

    private:
        ProjectStorage* storage;
        RealProject* realProject;
};

#endif // PROXYPROJECT_H
