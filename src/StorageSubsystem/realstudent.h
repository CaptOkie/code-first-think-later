#ifndef REALSTUDENT_H
#define REALSTUDENT_H

#include "student.h"

class RealStudent : Student
{
    public:
        RealStudent(int id, QString* name);
        ~RealStudent();

        const QMap<int, Question*>& getQuestions() const;
        const QMap<QString, Project*>& getEnrolledProjects() const;
        const QMap<QString, Project*>& getAvailableProject() const;

        void joinProject(const Project& project);
        void leaveProject(const Project& project);

};

#endif // REALSTUDENT_H
