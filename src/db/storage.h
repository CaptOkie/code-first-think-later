#ifndef STORAGE_H
#define STORAGE_H

#include <QtSql>

#include "../enum/usertype.h"

class Storage
{
    public:
        Storage();
        ~Storage();

        // Add entries into their tables
        void addUser(QString&, UserType);
        bool addProject(QString&);

        // Select entries from database
        bool validUser(QString&, UserType*);
        bool validUser(int, UserType*);

    private:
        // Attributes
        QSqlDatabase db;

        // Creates tables for database (If not exist)
        void setupDB();
};

#endif // STORAGE_H
