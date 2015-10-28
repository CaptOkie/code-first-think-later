#ifndef STORAGE_H
#define STORAGE_H

#include <QtSql>
#include <string>

using namespace std;

class Storage
{
    public:
        Storage();
        ~Storage();

        // Adding entries into their tables
        bool addStudent(string&);
        bool addAdmin(string&);
        bool addProject(string&);

    private:
        // Attributes
        QSqlDatabase db;

        // Creates tables for database (If not exist)
        void setupDB();
};

#endif // STORAGE_H
