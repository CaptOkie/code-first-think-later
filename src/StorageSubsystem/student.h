#ifndef STUDENT_H
#define STUDENT_H

#include <QMap>

#include "user.h"
#include "question.h"

class Project;

class Student: public User
{
    public:
        Student();
        virtual ~Student();

        virtual const QMap<int, Question>& getQuestions() const;
        virtual const QMap<QString, Project>& getEnrolledProjects() const;
        virtual const QMap<QString, Project>& getAvailableProject() const;

        virtual void joinProject(const Project& project);
        virtual void leaveProject(const Project& project);
};

#endif // STUDENT_H
