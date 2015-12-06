#include "admincontrol.h"

AdminControl::AdminControl(Admin* admin)
    : adminForm(*this), admin(admin), projectControl(*this, NULL)
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

void AdminControl::addNewProject(RealProject& project)
{
    if (admin->addProject(project)) {
        adminForm.update(admin->getProjects());
    }
}

void AdminControl::udpdateProject(const QString& oldProject)
{
    QMap<QString, Project*>& projects = admin->getProjects();
    Project* project = projects.take(oldProject);
    if (project)
    {
        projects.insert(project->getName(), project);
        refresh();
    }
}

void AdminControl::refresh()
{
    adminForm.update(admin->getProjects());
}

void AdminControl::runPPID(QString projectName)
{
    QMap<QString, Project*>& projects = admin->getProjects();
    Project* selectedProject = projects.find(projectName).value();
    //ppidControl.start(selectedProject);
}

void AdminControl::deleteProject(QString projectName)
{
    QMap<QString, Project*>& projects = admin->getProjects();
    Project* remove = projects.value(projectName, NULL);
    if (remove)
    {
        remove = admin->deleteProject(*remove);
        if (remove)
        {
            delete remove;
            refresh();
        }
    }
}
