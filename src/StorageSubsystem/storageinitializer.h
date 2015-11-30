#ifndef STORAGEINITIALIZER_H
#define STORAGEINITIALIZER_H

#include <QSqlDatabase>

#include "storage.h"

class StorageInitializer
{
    public:
        StorageInitializer();
        ~StorageInitializer();

        void init(QSqlDatabase& db);

        void populate();
};

#endif // STORAGEINITIALIZER_H
