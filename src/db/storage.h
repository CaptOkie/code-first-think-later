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
        void addUser(QString&, UserType type);
        void addProject(QString&);

        // Select entries from database
        int validUser(QString&);

    private:
        // Attributes
        QSqlDatabase db;

        // Creates tables for database (If not exist)
        void setupDB();
};

#endif // STORAGE_H
