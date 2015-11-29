#ifndef ADMINSTORAGE_H
#define ADMINSTORAGE_H

#include <QtSql>
#include <QMap>

#include "admin.h"

class AdminStorage
{
    public:
        AdminStorage();
        ~AdminStorage();

        QMap<QString, Project>* getProjects(const Admin& admin);

        void deleteProject(const Admin& admin, const Project& project);
        void addProject(const Admin& admin, const Project& project);

    private:
        QSqlDatabase& db;
};

#endif // ADMINSTORAGE_H
