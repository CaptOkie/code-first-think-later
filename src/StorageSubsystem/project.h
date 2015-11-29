#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <list>
#include "group.h"

class Student;

class Project
{
public:
    Project();
    ~Project();

    std::list<Student> getStudents();
    std::list<Group> getGroups();
    void setGroups(std::list<Group>);

protected:
    int id;
    std::string name;
    int maxGroupSize;
    int minGroupSize;
};

#endif // PROJECT_H
