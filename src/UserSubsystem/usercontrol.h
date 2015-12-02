#ifndef USERCONTROL_H
#define USERCONTROL_H

#include "StorageSubsystem/user.h"

class UserControl
{
    public:
        UserControl();
        virtual ~UserControl();

        virtual void start() = 0;
};

#endif // USERCONTROL_H
