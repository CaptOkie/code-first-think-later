#include "usercontrolfactory.h"

#include "StorageSubsystem/userstorage.h"

UserControlFactory::UserControlFactory()
{
}

UserControl* UserControlFactory::getUser(QString id, QString type){
    if (type == "admin"){
        return UserStorage::getAdmin(id.toInt()); //temporary going to fix
    }
    else {
        return UserStorage::getStudent(id.toInt()); //temporary going to fix
    }
}
