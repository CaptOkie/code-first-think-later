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
    UserControlFactory();
    ~UserControlFactory();

    UserControl* getUser(QString, QString); //id, type

private:
    UserStorage storage;
    AdminControl* admin;
    StudentControl* student;
};

#endif // USERCONTROLFACTORY_H
