#ifndef ADMINSTORAGE_H
#define ADMINSTORAGE_H

#include <QtSql>
#include <QList>

class AdminStorage
{
public:
    AdminStorage();
    ~AdminStorage();

private:
    QSqlDatabase db;
    //void setupDB();
    //void populateDatabase();
};

#endif // ADMINSTORAGE_H
