#include "group.h"

Group::Group(int id, QMap<int, Student*>* students)
    : id(id), students(students)
{ }

Group::~Group()
{
    delete students;
}

int Group::getId() const
{
    return id;
}

QMap<int, Student*>& Group::getStudents()
{
    return *students;
}

const QMap<int, Student*>& Group::getStudents() const
{
    return *students;
}
