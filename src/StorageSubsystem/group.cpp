#include "group.h"

Group::Group(int id, QMap<int, Student*>* students)
    : id(id), students(students)
{ }

Group::Group()
    : id(-1), students(new QMap<int, Student*>)
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
