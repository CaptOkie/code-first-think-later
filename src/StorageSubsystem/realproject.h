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

        virtual bool setName(QString* newName);
        virtual bool setMinGroupSize(int newMinGroupSize);
        virtual bool setMaxGroupSize(int newMaxGroupSize);

        const QMap<int, Student*>& getStudents() const;
        const QMap<int, Group*>& getGroups() const;

        void setStudents(QMap<int, Student*>* students);

        void setGroups(QList<Group*>& groups);
        void setGroups(QMap<int, Group*>* groups);

    private:
        int id;
        QString* name;
        int minGroupSize;
        int maxGroupSize;

        QMap<int, Student*>* students;
        QMap<int, Group*>*   groups;
};

#endif // REALPROJECT_H
