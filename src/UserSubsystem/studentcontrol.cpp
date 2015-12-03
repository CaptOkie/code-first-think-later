#include "studentcontrol.h"

StudentControl::StudentControl(Student* student)
    : stuForm(*this), student(student), editProfileControl(student)
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
