#include "studentstorage.h"

StudentStorage::StudentStorage(QSqlDatabase& db)
    : db(db)
{ }

StudentStorage::~StudentStorage()
{ }
