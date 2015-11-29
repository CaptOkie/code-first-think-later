#include "studentstorage.h"

StudentStorage::StudentStorage()
{
}

StudentStorage::~StudentStorage()
{
    if(db.isOpen()) {
        db.close();
    }
    QSqlDatabase::removeDatabase(db.connectionName());
}
