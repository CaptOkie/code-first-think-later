#include "realstudent.h"

RealStudent::RealStudent(int id, QString* name)
    : Student(id, name)
{ }

RealStudent::~RealStudent()
{ }

const QMap<int, Question*>& RealStudent::getQuestions() const
{

}

const QMap<QString, Project*>& RealStudent::getEnrolledProjects() const
{

}

const QMap<QString, Project*>& RealStudent::getAvailableProject() const
{

}

void RealStudent::joinProject(const Project& project)
{

}

void RealStudent::leaveProject(const Project& project)
{

}
