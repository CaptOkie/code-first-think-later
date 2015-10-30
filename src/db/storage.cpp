#include "storage.h"
#include <iostream>

// Table names and columns
// Student table
#define USER_TABLE    "users"
#define USER_ID_COL   "id"
#define USER_NAME_COL "name"
#define USER_TYPE_COL "type"
// Project table
#define PRO_TABLE     "projects"
#define PRO_NAME_COL  "name"

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
                     " (" PRO_NAME_COL " text PRIMARY KEY NOT NULL)");
    db.close();
}

void Storage::addUser(QString& name, UserType type) {
    db.open();
    QSqlQuery insert = QSqlQuery(db);
    insert.prepare("INSERT INTO " USER_TABLE " (" USER_NAME_COL " , " USER_TYPE_COL ") "
                   "VALUES (:name, :type)");
    insert.bindValue(":name", name);
    insert.bindValue(":type", type);
    insert.exec();
    db.close();
}

void Storage::addProject(QString& name) {
    db.open();
    QSqlQuery insert = QSqlQuery(db);
    insert.prepare("INSERT INTO " PRO_TABLE " (" PRO_NAME_COL ")"
                   "VALUES (:name)");
    insert.bindValue(":name", name);
    insert.exec();
    db.close();
}

int Storage::validUser(QString& name) {
    db.open();
    QSqlQuery select = QSqlQuery(db);
    select.prepare("SELECT * FROM " USER_NAME_COL " WHERE " USER_NAME_COL " =  :name");
    select.bindValue(":name", name);
    select.exec();

    if(select.first()) {
        db.close();
        return 1;
    }
    else {
        db.close();
        return -1;
    }
}
