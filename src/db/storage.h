#ifndef STORAGE_H
#define STORAGE_H

#include <QtSql>

class Storage
{
    public:
        Storage();
        ~Storage();

        // Adding entries into their tables
        void addStudent(QString&);
        void addAdmin(QString&);
        void addProject(QString&);

        // Select entries from database
        bool getStudent(QString&);

    private:
        // Attributes
        QSqlDatabase db;

        // Creates tables for database (If not exist)
        void setupDB();
};

#endif // STORAGE_H
