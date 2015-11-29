#include "userstorage.h"

UserStorage::UserStorage()
{

}

UserStorage::~UserStorage()
{
    if(db.isOpen()) {
        db.close();
    }
    QSqlDatabase::removeDatabase(db.connectionName());
}

Admin UserStorage::getAdmin(int id) {
    Admin ad;
    throw notAdminException;
    return ad;
}

Student UserStorage::getStudent(int id) {
    Student stu;
    throw notStudentException;
    return stu;
}
