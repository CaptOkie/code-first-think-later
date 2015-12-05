#ifndef PROXYSTUDENT_H
#define PROXYSTUDENT_H

#include "student.h"
#include "realstudent.h"
#include "studentstorage.h"

class ProxyStudent : public Student
{
    public:
        ProxyStudent(int id, QString* name, StudentStorage* storage);
        ProxyStudent(ProxyStudent& other);
        ~ProxyStudent();

        virtual int getId() const;
        virtual const QString& getName() const;

        const QMap<int, Question*>& getQuestions() const;
        const QMap<QString, Project*>& getEnrolledProjects() const;
        const QMap<QString, Project*>& getAvailableProject() const;

        void joinProject(const Project& project);
        void leaveProject(const Project& project);

    private:
        bool hasEnrolled;
        bool hasAvailable;
        RealStudent* realStudent;
        StudentStorage* storage;
};

#endif // PROXYSTUDENT_H
