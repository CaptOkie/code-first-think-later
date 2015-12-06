#include "realstudent.h"
#include "project.h"

RealStudent::RealStudent(int id, QString* name)
    : id(id), name(name), enrolled(new QMap<QString, Project*>()), available(new QMap<QString, Project*>()),
      questions(new QMap<int, Question*>())
{ }

RealStudent::~RealStudent()
{
    if (name)
        delete name;
    deleteProjects(enrolled);
    deleteProjects(available);
    deleteQuestions();
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
    return *questions;
}

const QMap<QString, Project*>& RealStudent::getEnrolledProjects() const
{
    return *enrolled;
}

const QMap<QString, Project*>& RealStudent::getAvailableProject() const
{
    return *available;
}

void RealStudent::setQuestions(QMap<int, Question*>* questions)
{
    deleteQuestions();
    this->questions = questions;
}

void RealStudent::setEnrolledProjects(QMap<QString, Project*>* projects)
{
    deleteProjects(enrolled);
    enrolled = projects;
}

void RealStudent::setAvailableProjects(QMap<QString, Project*>* projects)
{
    deleteProjects(available);
    available = projects;
}

bool RealStudent::joinProject(const Project& project)
{
    Project* join = available->take(project.getName());
    if (join)
    {
        enrolled->insert(join->getName(), join);
        return true;
    }

    return false;
}

bool RealStudent::leaveProject(const Project& project)
{
    Project* leave = enrolled->take(project.getName());
    if (leave)
    {
        available->insert(leave->getName(), leave);
        return true;
    }

    return false;
}

void RealStudent::deleteProjects(QMap<QString, Project*>* projects)
{
    if (projects)
    {
        for (QMap<QString, Project*>::iterator it = projects->begin(); it != projects->end(); ++it)
        {
            Project* project = it.value();
            delete project;
        }

        delete projects;
    }
}

void RealStudent::deleteQuestions()
{
    if (questions)
    {
        for (QMap<int, Question*>::iterator it = questions->begin(); it != questions->end(); ++it)
        {
            Question* question = it.value();
            delete question;
        }

        delete questions;
    }
}
