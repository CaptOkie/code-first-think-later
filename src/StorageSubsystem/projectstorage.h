#ifndef PROJECTSTORAGE_H
#define PROJECTSTORAGE_H

#include <QtSql>
#include <QMap>
#include <QList>

#include "project.h"
#include "student.h"

class ProjectStorage
{
    public:
        ProjectStorage(QSqlDatabase& db);
        ProjectStorage(const ProjectStorage& other);
        ~ProjectStorage();

        bool updateProject(const Project& project);

        QMap<int, Student*>* getStudents(const Project& project);
        QMap<int, Group*>* getGroups(const Project& project);

        bool setGroups(const Project& project, const QList<Group*>& groups);
        bool setGroups(const Project& project, const QMap<int, Group*>& groups);

    private:
        QSqlDatabase& db;
};

#endif // PROJECTSTORAGE_H
