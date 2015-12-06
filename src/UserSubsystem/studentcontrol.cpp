#include "studentcontrol.h"

StudentControl::StudentControl(Student* student)
    : stuForm(*this), student(student), editProfileControl(*student)
{ }

StudentControl::~StudentControl()
{
    if (student) {
        delete student;
    }
}

void StudentControl::start()
{
    stuForm.setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            stuForm.size(),
            qApp->desktop()->availableGeometry()
        )
    );
    stuForm.setName(student->getName());
    const QMap<QString, Project*>& availableProject = student->getAvailableProject();
    const QMap<QString, Project*>& enrolledProject = student->getEnrolledProjects();
    stuForm.show(availableProject, enrolledProject);
}

void StudentControl::editProfile()
{
    editProfileControl.start();
}

void StudentControl::joinProject(QString project)
{
    const QMap<QString, Project*>& availableProjects = student->getAvailableProject();
    const Project& prjt = *(availableProjects.find(project).value());
    student->joinProject(prjt);
    const QMap<QString, Project*>& enrolledProjects = student->getEnrolledProjects();
    const QMap<QString, Project*>& newAvailableProjects = student->getAvailableProject();
    stuForm.show(newAvailableProjects, enrolledProjects);
}

void StudentControl::leaveProject(QString project)
{
    const QMap<QString, Project*>& enrolledProjects = student->getEnrolledProjects();
    const Project& prjt = *(enrolledProjects.find(project).value());
    student->leaveProject(prjt);
    const QMap<QString, Project*>& availableProjects = student->getAvailableProject();
    const QMap<QString, Project*>& newEnrolledProjects = student->getEnrolledProjects();
    stuForm.show(availableProjects, newEnrolledProjects);
}
