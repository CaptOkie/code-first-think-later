#ifndef PROJECTCONTROL_H
#define PROJECTCONTROL_H

#include "StorageSubsystem/project.h"
#include "projectform.h"

class ProjectControl
{
public:
    ProjectControl(Project*);
    ~ProjectControl();

    void start();

private:
    Project* project;
    ProjectForm projectForm;
};

#endif // PROJECTCONTROL_H
