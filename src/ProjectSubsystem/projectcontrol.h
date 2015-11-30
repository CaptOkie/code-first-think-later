#ifndef PROJECTCONTROL_H
#define PROJECTCONTROL_H

#include "StorageSubsystem/project.h"

class ProjectControl
{
public:
    ProjectControl();
    ~ProjectControl();

    void start();
    void close();
    void showDialog();
};

#endif // PROJECTCONTROL_H
