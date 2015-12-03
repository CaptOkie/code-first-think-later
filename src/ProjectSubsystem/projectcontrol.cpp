#include "projectcontrol.h"

ProjectControl::ProjectControl(Project* project) : project(project), projectForm(*this)
{
}

ProjectControl::~ProjectControl()
{

}

void ProjectControl::start()
{
    if (project == NULL)
    {
        projectForm.setName("<New Project>");
    }
    else
    {
        projectForm.setName(project->getName());
    }
    projectForm.showDialog();
}

void ProjectControl::setProject(Project* newProject)
{
    project = newProject;
}
