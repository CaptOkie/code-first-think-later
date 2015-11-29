#include "adminstorage.h"

AdminStorage::AdminStorage()
{
}

AdminStorage::~AdminStorage()
{
    if(db.isOpen()) {
        db.close();
    }
    QSqlDatabase::removeDatabase(db.connectionName());
}
