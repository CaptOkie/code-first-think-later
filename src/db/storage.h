#ifndef STORAGE_H
#define STORAGE_H

#include <QtSql>

class Storage
{
    public:
        Storage();
        ~Storage();

    private:
        QSqlDatabase db;
};

#endif // STORAGE_H
