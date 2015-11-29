#include "usercontrolfactory.h"

#include "StorageSubsystem/userstorage.h"

UserControlFactory::UserControlFactory()
{
}

User UserControlFactory::getUser(QString id){
    User user;
    UserStorage storage;
    try {
        user = storage.getAdmin();
        return user;
    }
    catch (const notAdminException& e) {
        try {
            user = storage.getStudent();
            return user;
        }
        catch (const notStudentException& e) {
            throw noAccountException;
        }
    }
}
