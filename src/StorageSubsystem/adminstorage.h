#ifndef ADMINSTORAGE_H
#define ADMINSTORAGE_H

#include <QtSql>
#include <list>

#include "admin.h"

class AdminStorage
{
public:
    AdminStorage();
    ~AdminStorage();

    std::list<Project> getProjects(Admin);
    void deleteProject(Admin, Project);
    void addProject(Admin, Project);

private:
    QSqlDatabase db;
    //void setupDB();
    //void populateDatabase();
};

#endif // ADMINSTORAGE_H
