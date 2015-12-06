#ifndef PROXYSTUDENT_H
#define PROXYSTUDENT_H

#include "student.h"
#include "realstudent.h"
#include "studentstorage.h"
#include "indicator.h"
#include "project.h"

class ProxyStudent : public Student
{
    public:
        ProxyStudent(int id, QString* name, StudentStorage* storage);
        ~ProxyStudent();

        virtual int getId() const;
        virtual const QString& getName() const;

        const QMap<int, Question*>& getQuestions() const;
        const QMap<QString, Project*>& getEnrolledProjects() const;
        const QMap<QString, Project*>& getAvailableProject() const;

        void joinProject(const Project& project);
        void leaveProject(const Project& project);

    private:
        Indicator* hasEnrolled;
        Indicator* hasAvailable;
        Indicator* hasQuestions;
        RealStudent* realStudent;
        StudentStorage* storage;
};

#endif // PROXYSTUDENT_H
