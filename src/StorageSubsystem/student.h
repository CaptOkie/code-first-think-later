#ifndef STUDENT_H
#define STUDENT_H

#include <QMap>

#include "user.h"
#include "question.h"

class Project;

class Student: public User
{
    public:
        Student(int id, QString* name);
        virtual ~Student();

        virtual const QMap<int, Question*>& getQuestions() const = 0;
        virtual const QMap<QString, Project*>& getEnrolledProjects() const = 0;
        virtual const QMap<QString, Project*>& getAvailableProject() const = 0;

        virtual void joinProject(const Project& project) = 0;
        virtual void leaveProject(const Project& project) = 0;
};

#endif // STUDENT_H
