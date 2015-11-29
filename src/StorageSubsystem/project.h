#ifndef PROJECT_H
#define PROJECT_H

#include <QString>
#include <QMap>
#include <QList>
#include <QString>

#include "group.h"

class Student;

class Project
{
    public:
        Project();
        virtual ~Project();

        int getId() const;
        const QString& getName() const;
        int getMaxGroupSize() const;
        int getMinGroupSize() const;

        virtual const QMap<int, Student>& getStudents() const;
        virtual const QMap<int, Group>& getGroups() const;

        virtual void setGroups(const QList<Group>& groups);
        virtual void setGroups(const QMap<int, Group>& groups);

    protected:
        int id;
        QString* name;
        int maxGroupSize;
        int minGroupSize;
};

#endif // PROJECT_H
