#include "storage.h"
#include <iostream>

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
    QSqlQuery query = db.exec("CREATE TABLE IF NOT EXISTS students (name text, id integer PRIMARY KEY ASC AUTOINCREMENT)");
    query = db.exec("CREATE TABLE IF NOT EXISTS admin (name text, id integer PRIMARY KEY ASC AUTOINCREMENT)");
}
