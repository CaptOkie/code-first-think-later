#ifndef USERCONTROLFACTORY_H
#define USERCONTROLFACTORY_H

#include <QString>
#include "UserSubsystem/usercontrol.h"
#include "UserSubsystem/admincontrol.h"
#include "UserSubsystem/studentcontrol.h"
#include "StorageSubsystem/userstorage.h"

class UserControlFactory
{
public:
    enum Type {
        StudentType, AdminType
    };

public:
    UserControlFactory();
    ~UserControlFactory();

    UserControl* getUser(int id, Type type);

private:
    UserStorage storage;
};

#endif // USERCONTROLFACTORY_H
