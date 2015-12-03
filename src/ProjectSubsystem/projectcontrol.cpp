#include "projectcontrol.h"

ProjectControl::ProjectControl(Project* project) : project(project)
{
}

ProjectControl::~ProjectControl()
{

}

void ProjectControl::start()
{
    projectForm.showDialog();
}
