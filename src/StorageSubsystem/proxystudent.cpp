#include "proxystudent.h"

ProxyStudent::ProxyStudent(int id, QString* name, StudentStorage* storage)
    : Student(id, name), realStudent(NULL), storage(storage)
{ }

ProxyStudent::~ProxyStudent()
{
    if(realStudent)
        delete realStudent;

    if(storage)
        delete storage;
}

const QMap<int, Question*>& ProxyStudent::getQuestions() const
{

}

const QMap<QString, Project*>& ProxyStudent::getEnrolledProjects() const
{

}

const QMap<QString, Project*>& ProxyStudent::getAvailableProject() const
{

}

void ProxyStudent::joinProject(const Project& project)
{

}

void ProxyStudent::leaveProject(const Project& project)
{

}
