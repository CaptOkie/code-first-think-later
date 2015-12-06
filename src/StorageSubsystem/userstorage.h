#ifndef USERSTORAGE_H
#define USERSTORAGE_H

#include <QtSql>

#include "admin.h"
#include "student.h"

/**
 * @brief The UserStorage class. Access information in the database to retrieve a Student or an Admin.
 */
class UserStorage
{
    public:
        UserStorage();
        ~UserStorage();

        /**
         * @brief getStudent Gets a Student from the database based on a given id.
         * @param id Student's id.
         * @return The Student.
         */
        Student* getStudent(int id);
        /**
         * @brief getAdmin Gets an Admin from the database base on a given id.
         * @param id Admin's id.
         * @return The Admin.
         */
        Admin* getAdmin(int id);

    private:
        /**
         * @brief db The database connection.
         */
        QSqlDatabase db;
};

#endif // USERSTORAGE_H
