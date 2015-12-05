#include "projectcontrol.h"

#include "UserSubsystem/admincontrol.h"

ProjectControl::ProjectControl(AdminControl& ctrl, Project* project) : project(project), projectForm(*this), ctrl(ctrl)
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
        projectForm.setValue("min", 0);
        projectForm.setValue("max", 0);
    }
    else
    {
        projectForm.setName(project->getName());
        projectForm.setValue("min", project->getMinGroupSize());
        projectForm.setValue("max", project->getMaxGroupSize());
    }
    projectForm.showDialog();
}

void ProjectControl::setProject(Project* newProject)
{
    project = newProject;
}

void ProjectControl::saveProject(QString name, QString min, QString max)
{
    if (project == NULL)
    {
        RealProject realProject = RealProject(0, new QString(name), min.toInt(), max.toInt());
        ctrl.addNewProject(realProject);
    }
    else
    {
        QString oldProject = QString(project->getName());
        project->setName(new QString(name));
        project->setMinGroupSize(min.toInt());
        project->setMaxGroupSize(max.toInt());
        ctrl.udpdateProject(oldProject);
    }
}
