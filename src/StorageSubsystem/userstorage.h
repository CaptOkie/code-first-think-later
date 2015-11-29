#ifndef USERSTORAGE_H
#define USERSTORAGE_H

#include <QtSql>

#include "admin.h"
#include "student.h"

class UserStorage
{
    public:
        UserStorage(QSqlDatabase& db);
        ~UserStorage();

        Student* getStudent(int id);
        Admin* getAdmin(int id);

    private:
        QSqlDatabase& db;
};

#endif // USERSTORAGE_H
