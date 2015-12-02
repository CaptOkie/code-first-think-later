#include "userstorage.h"
#include "storageinitializer.h"
#include "proxyadmin.h"
#include "adminstorage.h"
#include "proxystudent.h"
#include "studentstorage.h"

UserStorage::UserStorage()
    : db(QSqlDatabase::addDatabase("QSQLITE"))
{
    db.setDatabaseName(DATABASE_NAME);
    StorageInitializer init;
    init.init(db);
}

UserStorage::~UserStorage()
{
    if(db.isOpen()) {
        db.close();
    }
    QString name = db.connectionName();
    db = QSqlDatabase();
    db.removeDatabase(name);
}

Admin* UserStorage::getAdmin(int id) {
    ProxyAdmin* admin = NULL;

    db.open();

    QSqlQuery select(db);
    select.prepare("SELECT * FROM " ADMN_TABLE " WHERE " ADMN_ID_COL " = :id");
    select.bindValue(":id", id);
    select.exec();

    if (select.first()) {
        int id = select.value(ADMN_ID_COL).toInt();
        QString name = (QString)select.value(ADMN_NAME_COL).toString();
        admin = new ProxyAdmin(id, new QString(name), new AdminStorage(db));
    }

    db.close();
    return admin;
}

Student* UserStorage::getStudent(int id) {
    ProxyStudent* student = NULL;

    db.open();

    QSqlQuery select(db);
    select.prepare("SELECT * FROM " STU_TABLE " WHERE " STU_ID_COL " = :id");
    select.bindValue(":id", id);
    select.exec();

    if (select.first()) {
        int id = select.value(STU_ID_COL).toInt();
        QString name = (QString)select.value(STU_NAME_COL).toString();
        student = new ProxyStudent(id, new QString(name), new StudentStorage(db));
    }

    db.close();
    return student;
}
