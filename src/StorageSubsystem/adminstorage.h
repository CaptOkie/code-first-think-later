#ifndef ADMINSTORAGE_H
#define ADMINSTORAGE_H

#include <QtSql>
#include <QMap>

#include "admin.h"
#include "storage.h"

class AdminStorage
{
    public:
        AdminStorage(QSqlDatabase& db);
        ~AdminStorage();

        QMap<QString, Project*>* getProjects();

        void deleteProject(const Project& project);
        void addProject(const Project& project);

    private:
        QSqlDatabase& db;
};

#endif // ADMINSTORAGE_H
