#ifndef USERCONTROLFACTORY_H
#define USERCONTROLFACTORY_H

#include <QString>
#include "StorageSubsystem/user.h"

class UserControlFactory
{
public:
    UserControlFactory();
    ~UserControlFactory();

    User getUser(QString);
};

#endif // USERCONTROLFACTORY_H
