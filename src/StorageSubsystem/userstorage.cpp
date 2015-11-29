#include "userstorage.h"
#include "storageinitializer.h"
#include "proxyadmin.h"

UserStorage::UserStorage(QSqlDatabase& db)
    : db(db)
{
    StorageInitializer init = StorageInitializer();
    init.init(db);
}

UserStorage::~UserStorage()
{ }

Admin* UserStorage::getAdmin(int id) {
    RealAdmin* admin = NULL;

    db.open();

    QSqlQuery select(db);
    select.prepare("SELECT * FROM " ADMN_TABLE " WHERE " ADMN_ID_COL " = :id");
    select.bindValue(":id", id);
    select.exec();

    if(select.first()) {
        int id = select.value(ADMN_ID_COL).toInt();
        QString name = (QString)select.value(ADMN_NAME_COL).toString();
        admin = new RealAdmin(id, new QString(name));
    }

    db.close();
    return admin;
}

Student* UserStorage::getStudent(int id) {
    Student stu;
    return &stu;
}
