#include "storage.h"

Storage::Storage()
    : db(QSqlDatabase::addDatabase("QSQLITE"))
{
    db.setDatabaseName("cuPID.db");
}

Storage::~Storage() {
    db.close();
    QSqlDatabase::removeDatabase(db.connectionName());
}
