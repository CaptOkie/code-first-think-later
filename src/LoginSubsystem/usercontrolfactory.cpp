#include "usercontrolfactory.h"

#include "StorageSubsystem/userstorage.h"

UserControlFactory::UserControlFactory()
{
}

UserControl* UserControlFactory::getUser(QString id, QString type){
    if (type == "admin"){
        return NULL;
    }
    else {
        return NULL;
    }
}
