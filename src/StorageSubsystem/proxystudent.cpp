#include "proxystudent.h"

ProxyStudent::ProxyStudent(int id, QString* name, StudentStorage* storage)
    : hasEnrolled(new Indicator(false)), hasAvailable(new Indicator(false)), realStudent(new RealStudent(id, name)),
      storage(storage)
{ }

ProxyStudent::ProxyStudent(ProxyStudent& other)
    : ProxyStudent(other.getId(), new QString(other.getName()), new StudentStorage(*(other.storage)))
{ }

ProxyStudent::~ProxyStudent()
{
    if (hasEnrolled)
        delete hasEnrolled;
    if (hasAvailable)
        delete hasAvailable;
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
    if (!hasEnrolled->getValue())
    {
        hasEnrolled->toggleValue();
        realStudent->setEnrolledProjects(storage->getEnrolledProjects(*realStudent));
    }
    return realStudent->getEnrolledProjects();
}

const QMap<QString, Project*>& ProxyStudent::getAvailableProject() const
{
    if (!hasAvailable->getValue())
    {
        hasAvailable->toggleValue();
        realStudent->setAvailableProjects(storage->getAvailableProjects(*realStudent));
    }
    return realStudent->getAvailableProject();
}

void ProxyStudent::joinProject(const Project& project)
{

}

void ProxyStudent::leaveProject(const Project& project)
{

}
