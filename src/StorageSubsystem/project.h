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

        virtual int getId() const = 0;
        virtual const QString& getName() const = 0;
        virtual int getMinGroupSize() const = 0;
        virtual int getMaxGroupSize() const = 0;

        virtual bool setName(QString* newName) = 0;
        virtual bool setMinGroupSize(int newMinGroupSize) = 0;
        virtual bool setMaxGroupSize(int newMaxGroupSize) = 0;

        virtual const QMap<int, Student*>& getStudents() const = 0;
        virtual const QMap<int, Group*>& getGroups() const = 0;

        virtual void setGroups(const QList<Group*>& groups) = 0;
};

#endif // PROJECT_H
