#include "realstudent.h"

RealStudent::RealStudent(int id, QString* name)
    : id(id), name(name)
{ }

RealStudent::~RealStudent()
{
    if (name)
        delete name;
}

int RealStudent::getId() const
{
    return id;
}

const QString& RealStudent::getName() const
{
    return *name;
}

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
