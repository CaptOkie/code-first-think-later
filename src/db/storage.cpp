#include "storage.h"
#include <iostream>

// Table names and columns
// Student table
#define USER_TABLE    "users"
#define USER_ID_COL   "id"
#define USER_NAME_COL "name"
#define USER_TYPE_COL "type"
// Project table
#define PRO_TABLE       "projects"
#define PRO_NAME_COL    "name"
#define PRO_MAX_GRP_COL "max_grp_size"
#define PRO_MIN_GRP_COL "min_grp_size"

#include <QDebug>

Storage::Storage()
    : db(QSqlDatabase::addDatabase("QSQLITE"))
{
    db.setDatabaseName("cuPID.db");
    setupDB();
}

Storage::~Storage() {
    if(db.isOpen()) {
        db.close();
    }
    QSqlDatabase::removeDatabase(db.connectionName());
}

void Storage::setupDB() {
    db.open();
    QSqlQuery create;
    create = db.exec("CREATE TABLE IF NOT EXISTS " USER_TABLE
                     " (" USER_ID_COL " integer PRIMARY KEY ASC AUTOINCREMENT NOT NULL, "
                     USER_NAME_COL " text NOT NULL, "
                     USER_TYPE_COL " integer NOT NULL)");
    create = db.exec("CREATE TABLE IF NOT EXISTS " PRO_TABLE
                     " (" PRO_NAME_COL " text PRIMARY KEY NOT NULL, "
                     PRO_MAX_GRP_COL " integer NOT NULL, "
                     PRO_MIN_GRP_COL " integer NOT NULL)");

    QSqlQuery insert;
    insert = db.exec("INSERT INTO " USER_TABLE " (name, type) SELECT 'a', 1 "
                     "WHERE NOT EXISTS (SELECT * FROM " USER_TABLE " WHERE " USER_TYPE_COL " = 1)");
    insert = db.exec("INSERT INTO " USER_TABLE " (name, type) SELECT 's', 0 "
                     "WHERE NOT EXISTS (SELECT * FROM " USER_TABLE " WHERE " USER_TYPE_COL " = 0)");

    db.close();
}

void Storage::addUser(QString& name, User::Type type) {
    db.open();
    QSqlQuery insert = QSqlQuery(db);
    insert.prepare("INSERT INTO " USER_TABLE " (" USER_NAME_COL " , " USER_TYPE_COL ") "
                   "VALUES (:name, :type)");
    insert.bindValue(":name", name);
    insert.bindValue(":type", type);
    insert.exec();
    db.close();
}

bool Storage::addProject(QString& name) {
    db.open();
    QSqlQuery insert = QSqlQuery(db);
    insert.prepare("INSERT INTO " PRO_TABLE " (" PRO_NAME_COL ")"
                   "VALUES (:name)");
    insert.bindValue(":name", name);
    insert.exec();
    db.close();

    return true;
}

bool Storage::validUser(QString& idStr, User** user) {
    return validUser(atoi(idStr.toStdString().c_str()), user);
}

bool Storage::validUser(int id, User** user) {
    db.open();
    QSqlQuery select = QSqlQuery(db);
    select.prepare("SELECT * FROM " USER_TABLE " WHERE " USER_ID_COL " = :id");
    select.bindValue(":id", id);
    select.exec();

    if(select.first()) {
        int id = select.value(USER_ID_COL).toInt();
        User::Type type = (User::Type)select.value(USER_TYPE_COL).toInt();
        QString name = (QString)select.value(USER_NAME_COL).toString();
        *user = new User(id, type, new QString(name));

        db.close();
        return true;
    }
    db.close();
    return false;
}
