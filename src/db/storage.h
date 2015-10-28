#ifndef STORAGE_H
#define STORAGE_H

#include <QtSql>

class Storage
{
    public:
        Storage();
        ~Storage();


    private:
        // Attributes
        QSqlDatabase db;

        void setupDB();
};

#endif // STORAGE_H
