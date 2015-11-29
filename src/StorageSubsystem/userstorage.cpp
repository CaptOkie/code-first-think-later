#include "userstorage.h"

UserStorage::UserStorage()
{

}

UserStorage::~UserStorage()
{
    if(db.isOpen()) {
        db.close();
    }
    QSqlDatabase::removeDatabase(db.connectionName());
}
