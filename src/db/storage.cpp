#include "storage.h"
#include <iostream>

// Table names and columns
// Student table
#define STU_TABLE      "students"
#define STU_NAME_COL   "name"
// Admin table
#define ADMIN_TABLE    "admins"
#define ADMIN_NAME_COL "name"
// Project table
#define PRO_TABLE      "projects"
#define PRO_NAME_COL   "name"

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
    create = db.exec("CREATE TABLE IF NOT EXISTS " STU_TABLE
                     " (id integer PRIMARY KEY ASC AUTOINCREMENT NOT NULL, " STU_NAME_COL " text)");
    create = db.exec("CREATE TABLE IF NOT EXISTS " ADMIN_TABLE
                     " (id integer PRIMARY KEY ASC AUTOINCREMENT NOT NULL, " ADMIN_NAME_COL " text)");
    create = db.exec("CREATE TABLE IF NOT EXISTS " PRO_TABLE
                     " (" PRO_NAME_COL " text PRIMARY KEY NOT NULL)");
    db.close();
}

void Storage::addStudent(QString& name) {
    db.open();
    QSqlQuery insert = QSqlQuery(db);
    insert.prepare("INSERT INTO " STU_TABLE " (" STU_NAME_COL ")"
                   "VALUES (:name)");
    insert.bindValue(":name", name);
    insert.exec();
    db.close();
}

void Storage::addAdmin(QString& name) {
    db.open();
    QSqlQuery insert = QSqlQuery(db);
    insert.prepare("INSERT INTO " ADMIN_TABLE " (" ADMIN_NAME_COL ")"
                   "VALUES (:name)");
    insert.bindValue(":name", name);
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

bool Storage::getStudent(QString& name) {
    db.open();
    QSqlQuery select = QSqlQuery(db);
    select.prepare("SELECT FROM " STU_TABLE " WHERE " STU_NAME_COL " = ?"
                   "VALUES (:name)");
    select.bindValue(":name", name);
    select.exec();
    db.close();

    return true;
}
