#include "proxystudent.h"

ProxyStudent::ProxyStudent(int id, QString* name, StudentStorage* storage)
    : hasEnrolled(new Indicator(false)), hasAvailable(new Indicator(false)), hasQuestions(new Indicator(false)),
      realStudent(new RealStudent(id, name)), storage(storage)
{ }

ProxyStudent::~ProxyStudent()
{
    if (hasEnrolled)
        delete hasEnrolled;
    if (hasAvailable)
        delete hasAvailable;
    if (hasQuestions)
        delete hasQuestions;
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
    if (!hasQuestions->getValue())
    {
        hasQuestions->toggleValue();
        QMap<int, Question*>* questions = storage->getQuestions(*realStudent);
        realStudent->setQuestions(questions);
    }
    return realStudent->getQuestions();
}

const QMap<QString, Project*>& ProxyStudent::getEnrolledProjects() const
{
    if (!hasEnrolled->getValue())
    {
        hasEnrolled->toggleValue();
        QMap<QString, Project*>* projects = storage->getEnrolledProjects(*realStudent);
        realStudent->setEnrolledProjects(projects);
    }
    return realStudent->getEnrolledProjects();
}

const QMap<QString, Project*>& ProxyStudent::getAvailableProject() const
{
    if (!hasAvailable->getValue())
    {
        hasAvailable->toggleValue();
        QMap<QString, Project*>* projects = storage->getAvailableProjects(*realStudent);
        realStudent->setAvailableProjects(projects);
    }
    return realStudent->getAvailableProject();
}

bool ProxyStudent::joinProject(const Project& project)
{
    if (storage->joinProject(*realStudent, project))
        return realStudent->joinProject(project);
    return false;
}

bool ProxyStudent::leaveProject(const Project& project)
{
    if (storage->leaveProject(*realStudent, project))
        return realStudent->leaveProject(project);
    return false;
}
