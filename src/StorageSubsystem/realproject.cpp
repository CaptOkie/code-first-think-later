#include "realproject.h"

RealProject::RealProject(int id, QString* name, int minGroupSize, int maxGroupSize)
    : id(id), name(name), minGroupSize(minGroupSize), maxGroupSize(maxGroupSize),
      students(new QMap<int, Student*>), groups(new QMap<int, Group*>)
{ }

RealProject::~RealProject()
{
    if (name)
        delete name;
    clearGroups();
    clearStudents();
}

int RealProject::getId() const
{
    return id;
}

const QString& RealProject::getName() const
{
    return *name;
}

int RealProject::getMinGroupSize() const
{
    return minGroupSize;
}

int RealProject::getMaxGroupSize() const
{
    return maxGroupSize;
}

bool RealProject::setName(QString *newName)
{
    if (name)
        delete name;
    name = newName;
    return true;
}

bool RealProject::setMinGroupSize(int newMinGroupSize)
{
    minGroupSize = newMinGroupSize;
    return true;
}

bool RealProject::setMaxGroupSize(int newMaxGroupSize)
{
    maxGroupSize = newMaxGroupSize;
    return true;
}

const QMap<int, Student*>& RealProject::getStudents() const
{
    return *students;
}

const QMap<int, Group*>& RealProject::getGroups() const
{
    return *groups;
}

void RealProject::setStudents(QMap<int, Student*>* students)
{
    clearStudents();
    this->students = students;
}

bool RealProject::setGroups(QList<Group*>& groups)
{
    if (this->groups)
    {
        for (QMap<int, Group*>::iterator it = this->groups->begin(); it != this->groups->end(); ++it)
        {
            Group* group = it.value();
            delete group;
        }
        this->groups->clear();
    }

    int id = 1;
    for (QList<Group*>::iterator it = groups.begin(); it != groups.end(); ++it)
    {
        this->groups->insert(id, *it);
        ++id;
    }
}

bool RealProject::setGroups(QMap<int, Group*>* groups)
{
    clearGroups();
    this->groups = groups;
}

void RealProject::clearStudents()
{
    if (students)
    {
        for (QMap<int, Student*>::iterator it = students->begin(); it != students->end(); ++it)
        {
            Student* student = *it;
            delete student;
        }
        delete students;
        students = NULL;
    }
}

void RealProject::clearGroups()
{
    if (groups)
    {
        for (QMap<int, Group*>::iterator it = groups->begin(); it != groups->end(); ++it)
        {
            Group* group = *it;
            delete group;
        }
        delete groups;
        groups = NULL;
    }
}
