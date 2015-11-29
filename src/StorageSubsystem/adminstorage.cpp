#include "adminstorage.h"

AdminStorage::AdminStorage(QSqlDatabase& db)
    : db(db)
{ }

AdminStorage::~AdminStorage()
{ }
