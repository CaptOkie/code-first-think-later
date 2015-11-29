#ifndef STORAGEINITIALIZER_H
#define STORAGEINITIALIZER_H

#include <QSqlDatabase>

#include "storage.h"

class StorageInitializer
{
    public:
        StorageInitializer(QSqlDatabase& db);
        ~StorageInitializer();

        void init(QSqlDatabase& db);
};

#endif // STORAGEINITIALIZER_H
