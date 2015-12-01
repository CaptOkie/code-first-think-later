#include "projectstorage.h"

ProjectStorage::ProjectStorage(QSqlDatabase& db)
    : db(db)
{ }

ProjectStorage::ProjectStorage(const ProjectStorage& other)
    : db(other.db)
{ }

ProjectStorage::~ProjectStorage()
{ }
