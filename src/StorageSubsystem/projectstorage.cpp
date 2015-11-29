#include "projectstorage.h"

ProjectStorage::ProjectStorage(QSqlDatabase& db)
    : db(db)
{
}

ProjectStorage::~ProjectStorage()
{
    if(db.isOpen()) {
        db.close();
    }
    QSqlDatabase::removeDatabase(db.connectionName());
}
