#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"
#include <string>

class Student: public User
{
public:
    Student();
    void getQuestions(); //Temporary
    void getEnrolledProjects(); //Temporary
    void getAvailableProject(); //Temporary
    void joinProject(); //Temporary
    void leaveProject(); //Temporary

protected:
    std::string name;
};

#endif // STUDENT_H
