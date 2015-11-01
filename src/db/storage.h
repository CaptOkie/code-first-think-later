#ifndef STORAGE_H
#define STORAGE_H

#include <QtSql>

#include "user.h"
#include "project.h"
#include <QList>

class Storage
{
    public:
        Storage();
        ~Storage();

        // Add entries into their tables
        void addUser(QString&, User::Type);
        bool addProject(QString&);

        // Select entries from database
        bool validUser(QString&, User**);
        bool validUser(int, User**);
        void getProjects(QList<Project>**);
        void getProjects(QList<QString>**, QList<QString>**, User&);
        void getProjects(QList<Project>**, QString&);

    private:
        // Attributes
        QSqlDatabase db;

        // Creates tables for database (If not exist)
        void setupDB();
};

#endif // STORAGE_H
