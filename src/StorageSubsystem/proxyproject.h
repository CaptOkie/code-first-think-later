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
        ProxyProject(const Project& other, ProjectStorage* storage);
        ~ProxyProject();

        virtual int getId() const;
        virtual const QString& getName() const;
        virtual int getMinGroupSize() const;
        virtual int getMaxGroupSize() const;

        virtual void setName(QString* newName);
        virtual void setMinGroupSize(int newMinGroupSize);
        virtual void setMaxGroupSize(int newMaxGroupSize);

        virtual const QMap<int, Student*>& getStudents() const;
        virtual const QMap<int, Group*>& getGroups() const;

        virtual void setGroups(const QList<Group*>& groups);

    private:
        RealProject* realProject;
        ProjectStorage* storage;
};

#endif // PROXYPROJECT_H
