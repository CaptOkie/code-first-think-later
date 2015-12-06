#ifndef PROJECTCONTROL_H
#define PROJECTCONTROL_H

#include "StorageSubsystem/project.h"
#include "projectform.h"

#include "StorageSubsystem/realproject.h"

class AdminControl;

class ProjectControl
{
public:
    ProjectControl(AdminControl&, Project*);
    ~ProjectControl();

    void start();
    void setProject(Project*);
    void saveProject(QString, QString, QString);
    bool checkValues(QString, QString);

private:
    Project* project;
    ProjectForm projectForm;
    AdminControl& ctrl;
};

#endif // PROJECTCONTROL_H
