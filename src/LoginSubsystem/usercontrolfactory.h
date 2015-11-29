#ifndef USERCONTROLFACTORY_H
#define USERCONTROLFACTORY_H

#include <QString>
#include "UserSubsystem/usercontrol.h"

class UserControlFactory
{
public:
    UserControlFactory();
    ~UserControlFactory();

    UserControl* getUser(QString, QString); //id, type
};

#endif // USERCONTROLFACTORY_H