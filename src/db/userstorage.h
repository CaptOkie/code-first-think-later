#ifndef USERSTORAGE_H
#define USERSTORAGE_H

#include <QtSql>
#include <QList>

class UserStorage
{
public:
    UserStorage();
    ~UserStorage();

private:
    QSqlDatabase db;
    //void setupDB();
    //void populateDatabase();
};

#endif // USERSTORAGE_H
