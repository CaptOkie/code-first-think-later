#ifndef REALSTUDENT_H
#define REALSTUDENT_H

#include "student.h"

class RealStudent : Student
{
    public:
        RealStudent(int id, QString* name);
        ~RealStudent();

        virtual int getId() const;
        virtual const QString& getName() const;

        const QMap<int, Question*>& getQuestions() const;
        const QMap<QString, Project*>& getEnrolledProjects() const;
        const QMap<QString, Project*>& getAvailableProject() const;

        void joinProject(const Project& project);
        void leaveProject(const Project& project);

    private:
        int id;
        QString* name;
};

#endif // REALSTUDENT_H
