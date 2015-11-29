#include "userstorage.h"
#include "storageinitializer.h"

UserStorage::UserStorage(QSqlDatabase& db)
    : db(db)
{
    StorageInitializer init = StorageInitializer();
    init.init(db);
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
