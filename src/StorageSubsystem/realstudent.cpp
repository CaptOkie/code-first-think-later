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

void RealStudent::joinProject(const Project& project)
{

}

void RealStudent::leaveProject(const Project& project)
{

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
