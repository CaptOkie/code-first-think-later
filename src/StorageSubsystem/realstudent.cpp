#include "realstudent.h"

RealStudent::RealStudent(int id, QString* name)
    : id(id), name(name), enrolled(new QMap<QString, Project*>()), available(new QMap<QString, Project*>())
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
    return *enrolled;
}

const QMap<QString, Project*>& RealStudent::getAvailableProject() const
{
    return *available;
}

void RealStudent::setEnrolledProjects(QMap<QString, Project*>* projects)
{
    if (enrolled)
        delete enrolled;
    enrolled = projects;
}

void RealStudent::setAvailableProjects(QMap<QString, Project*>* projects)
{
    if (available)
        delete available;
    available = projects;
}

void RealStudent::joinProject(const Project& project)
{

}

void RealStudent::leaveProject(const Project& project)
{

}
