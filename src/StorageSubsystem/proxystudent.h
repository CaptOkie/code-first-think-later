#ifndef PROXYSTUDENT_H
#define PROXYSTUDENT_H

#include "student.h"
#include "realstudent.h"

class ProxyStudent : public Student
{
    public:
        ProxyStudent(int id, QString* name);
        ~ProxyStudent();

        const QMap<int, Question>& getQuestions() const;
        const QMap<QString, Project>& getEnrolledProjects() const;
        const QMap<QString, Project>& getAvailableProject() const;

        void joinProject(const Project& project);
        void leaveProject(const Project& project);

    private:
        RealStudent realStudent;
};

#endif // PROXYSTUDENT_H
