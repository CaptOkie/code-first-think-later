#include "group.h"

Group::Group(int id, QMap<int, Student*>* students)
    : id(id), students(students), match(0)
{ }

Group::Group(const Group& other)
    : id(other.getId()), students(new QMap<int, Student*>(other.getStudents())), match(other.getMatch())
{ }

Group::Group()
    : id(-1), students(new QMap<int, Student*>), match(0)
{ }

Group::~Group()
{
    delete students;
}

int Group::getId() const
{
    return id;
}

void Group::setId(int id)
{
    this->id = id;
}

QMap<int, Student*>& Group::getStudents()
{
    return *students;
}

const QMap<int, Student*>& Group::getStudents() const
{
    return *students;
}

int Group::getMatch() const
{
    return match;
}

void Group::setMatch(int match)
{
    this->match = match;
}
