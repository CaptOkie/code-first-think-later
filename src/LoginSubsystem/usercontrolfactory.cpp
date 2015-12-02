#include "usercontrolfactory.h"

#include "StorageSubsystem/userstorage.h"

UserControlFactory::UserControlFactory()
{
}

UserControlFactory::~UserControlFactory()
{
}

UserControl* UserControlFactory::getUser(QString id, QString type){
    if (type == "admin"){
        /*
        UserStorage storage;
        AdminControl* admin;
        admin->user = storage.getAdmin(id.toInt()); //temporary going to fix
        return admin;
        */
        return NULL;
    }
    else {
        //return UserStorage::getStudent(id.toInt()); //temporary going to fix
        return NULL;
    }
}
