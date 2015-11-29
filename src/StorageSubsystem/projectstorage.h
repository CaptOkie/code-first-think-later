#ifndef PROJECTSTORAGE_H
#define PROJECTSTORAGE_H

#include <QtSql>
#include <QList>

#include "project.h"

class ProjectStorage
{
public:
    ProjectStorage();
    ~ProjectStorage();

    std::list<Student> getStudents(Project);
    std::list<Group> getGroups(Project);
    void setGroups(Project, std::list<Group>);

private:
    QSqlDatabase db;
    //void setupDB();
    //void populateDatabase();
};

#endif // PROJECTSTORAGE_H
