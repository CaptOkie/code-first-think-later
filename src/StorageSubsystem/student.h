#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <list>

#include "user.h"
#include "question.h"
#include "project.h"

class Student: public User
{
public:
    Student();
    ~Student();

    std::list<Question> getQuestions();
    std::list<Project> getEnrolledProjects();
    std::list<Project> getAvailableProject();
    void joinProject(Project);
    void leaveProject(Project);
};

#endif // STUDENT_H
