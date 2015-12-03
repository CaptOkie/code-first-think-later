#include "admincontrol.h"

AdminControl::AdminControl(Admin* admin)
    : adminForm(*this), admin(admin), projectControl(NULL)
{ }

AdminControl::~AdminControl()
{
    if (admin) {
        delete admin;
    }
}

void AdminControl::start()
{
    adminForm.setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            adminForm.size(),
            qApp->desktop()->availableGeometry()
        )
    );
    adminForm.setName(admin->getName());
    loadProjects();
}

void AdminControl::loadProjects()
{
    QMap<QString, Project*>& projects = admin->getProjects();
    adminForm.show(projects);
}

void AdminControl::newProjectStart()
{
    Project* project = NULL;
    editProject(project);
}

void AdminControl::editProjectStart(QString projectName)
{
    QMap<QString, Project*>& projects = admin->getProjects();
    Project* selectedProject = projects.find(projectName).value();
    editProject(selectedProject);
}

void AdminControl::editProject(Project* project)
{
    projectControl.setProject(project);
    projectControl.start();
}

const QMap<int, Student*>& AdminControl::getStuNames(QString& projectName)
{

    QMap<QString, Project*>& projects = admin->getProjects();
    Project* selectedProject = projects.find(projectName).value();
    const QMap<int, Student*>& students = selectedProject->getStudents();
    return students;
}
