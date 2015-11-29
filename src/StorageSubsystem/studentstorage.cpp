#include "studentstorage.h"

StudentStorage::StudentStorage(QSqlDatabase& db)
    : db(db)
{
}

StudentStorage::~StudentStorage()
{
    if(db.isOpen()) {
        db.close();
    }
    QSqlDatabase::removeDatabase(db.connectionName());
}
