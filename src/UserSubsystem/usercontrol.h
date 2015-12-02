#ifndef USERCONTROL_H
#define USERCONTROL_H

#include "StorageSubsystem/user.h"

class UserControl
{
public:
    UserControl();
    virtual ~UserControl();
    User* user;

    virtual void start();
};

#endif // USERCONTROL_H
