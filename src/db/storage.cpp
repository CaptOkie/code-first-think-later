#include "storage.h"
#include <iostream>

// Table names
#define STU_TABLE     "students"
#define ADMIN_TABLE   "admins"
#define PROJECT_TABLE "projects"

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
                     "(id integer PRIMARY KEY ASC AUTOINCREMENT NOT NULL, name text)");
    create = db.exec("CREATE TABLE IF NOT EXISTS " ADMIN_TABLE
                     "(id integer PRIMARY KEY ASC AUTOINCREMENT NOT NULL, name text)");
    create = db.exec("CREATE TABLE IF NOT EXISTS " PROJECT_TABLE
                     "(name text PRIMARY KEY NOT NULL)");
    db.close();
}

void Storage::addStudent(QString& name) {
    db.open();
    QSqlQuery insert = QSqlQuery(db);
    insert.prepare("INSERT INTO " STU_TABLE "(name)"
                   "VALUES (:name)");
    insert.bindValue(":name", name);
    insert.exec();
    db.close();
}

void Storage::addAdmin(QString& name) {
    db.open();
    QSqlQuery insert = QSqlQuery(db);
    insert.prepare("INSERT INTO " ADMIN_TABLE "(name)"
                   "VALUES (:name)");
    insert.bindValue(":name", name);
    insert.exec();
    db.close();
}

void Storage::addProject(QString& name) {
    db.open();
    QSqlQuery insert = QSqlQuery(db);
    insert.prepare("INSERT INTO " PROJECT_TABLE "(name)"
                   "VALUES (:name)");
    insert.bindValue(":name", name);
    insert.exec();
    db.close();
}
