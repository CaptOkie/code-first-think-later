#ifndef PROXYPROJECT_H
#define PROXYPROJECT_H

#include "project.h"
#include "realproject.h"
#include "projectstorage.h"

class ProxyProject : public Project
{
    public:
        ProxyProject(int id, QString* name, int minGroupSize, int maxGroupSize, ProjectStorage* storage);
        ProxyProject(const Project& other, ProjectStorage* storage);
        ~ProxyProject();

        virtual int getId() const;
        virtual const QString& getName() const;
        virtual int getMinGroupSize() const;
        virtual int getMaxGroupSize() const;

        virtual bool setName(QString* newName);
        virtual bool setMinGroupSize(int newMinGroupSize);
        virtual bool setMaxGroupSize(int newMaxGroupSize);

        virtual const QMap<int, Student*>& getStudents() const;
        virtual const QMap<int, Group*>& getGroups() const;

        virtual bool setGroups(QList<Group*>& groups);
        virtual bool setGroups(QMap<int, Group*>* groups);

    private:
        bool hasLoaded;
        RealProject* realProject;
        ProjectStorage* storage;
};

#endif // PROXYPROJECT_H
