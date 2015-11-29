#include "projectstorage.h"

ProjectStorage::ProjectStorage()
{
}

ProjectStorage::~ProjectStorage()
{
    if(db.isOpen()) {
        db.close();
    }
    QSqlDatabase::removeDatabase(db.connectionName());
}
