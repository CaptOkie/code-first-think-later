#ifndef STORAGEINITIALIZER_H
#define STORAGEINITIALIZER_H

#include <QtSql>

#include "storage.h"

/**
 * @brief The StorageInitializer class. Initializes the database.
 */
class StorageInitializer
{
    public:
        StorageInitializer();
        ~StorageInitializer();

        void init(QSqlDatabase& db);

    private:
        void populate(QSqlDatabase& db);
};

#endif // STORAGEINITIALIZER_H
