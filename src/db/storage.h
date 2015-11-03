#ifndef STORAGE_H
#define STORAGE_H

#include <QtSql>

#include "user.h"
#include "project.h"
#include "response.h"
#include "question.h"
#include <QList>

class Storage
{
    public:
        Storage();
        ~Storage();

        // Add/remove/update entries into their tables
        void addUser(QString&, User::Type);
        bool addProject(Project&);
        void updateProject(Project&, QString&);
        void removeProject(QString&);
        void enrollStudent(QString&, int);
        void unenrollStudent(QString&, int);
        void updateResponses(const QList<Response>&, int);

        // Select entries from database
        bool validUser(QString&, User**);
        bool validUser(int, User**);
        void getProjects(QList<Project>**);
        void getProjects(QList<QString>**, QList<QString>**, User&);
        void getProjects(QList<Project>**, QString&);
        void getResponses(QList<Question>&, int);

    private:
        // Attributes
        QSqlDatabase db;

        // Creates tables for database (If not exist)
        void setupDB();
};

#endif // STORAGE_H
