#ifndef REALPROJECT_H
#define REALPROJECT_H

#include "project.h"

class RealProject : public Project
{
    public:
        RealProject(int id, QString* name, int minGroupSize, int maxGroupSize);
        ~RealProject();

        virtual int getId() const;
        virtual const QString& getName() const;
        virtual int getMinGroupSize() const;
        virtual int getMaxGroupSize() const;

        virtual void setName(QString* newName);
        virtual void setMinGroupSize(int newMinGroupSize);
        virtual void setMaxGroupSize(int newMaxGroupSize);

        const QMap<int, Student*>& getStudents() const;
        const QMap<int, Group*>& getGroups() const;

        void setGroups(const QList<Group*>& groups);
        void setGroups(const QMap<int, Group*>* groups);

    private:
        int id;
        QString* name;
        int minGroupSize;
        int maxGroupSize;
};

#endif // REALPROJECT_H
