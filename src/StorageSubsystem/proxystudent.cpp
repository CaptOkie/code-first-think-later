#include "proxystudent.h"

ProxyStudent::ProxyStudent(int id, QString* name, StudentStorage* storage)
    : hasEnrolled(false), hasAvailable(false), realStudent(new RealStudent(id, name)), storage(storage)
{ }

ProxyStudent::ProxyStudent(ProxyStudent& other)
    : ProxyStudent(other.getId(), new QString(other.getName()), new StudentStorage(*(other.storage)))
{ }

ProxyStudent::~ProxyStudent()
{
    if (realStudent)
        delete realStudent;
    if (storage)
        delete storage;
}

int ProxyStudent::getId() const
{
    return realStudent->getId();
}

const QString& ProxyStudent::getName() const
{
    return realStudent->getName();
}

const QMap<int, Question*>& ProxyStudent::getQuestions() const
{

}

const QMap<QString, Project*>& ProxyStudent::getEnrolledProjects() const
{
    if (!hasEnrolled)
    {
        hasEnrolled = true;
        realStudent->setEnrolledProjects(storage->getEnrolledProjects());
    }
    return realStudent->getEnrolledProjects();
}

const QMap<QString, Project*>& ProxyStudent::getAvailableProject() const
{
    if (!hasAvailable)
    {
        hasAvailable = true;
        realStudent->setAvailableProjects(storage->getAvailableProjects());
    }
    return realStudent->getAvailableProject();
}

void ProxyStudent::joinProject(const Project& project)
{

}

void ProxyStudent::leaveProject(const Project& project)
{

}
