#ifndef REALSTUDENT_H
#define REALSTUDENT_H

#include "student.h"

class RealStudent : public Student
{
    public:
        RealStudent(int id, QString* name);
        ~RealStudent();

        virtual int getId() const;
        virtual const QString& getName() const;

        const QMap<int, Question*>& getQuestions() const;
        const QMap<QString, Project*>& getEnrolledProjects() const;
        const QMap<QString, Project*>& getAvailableProject() const;

        void setEnrolledProjects(QMap<QString, Project*>* projects);
        void setAvailableProjects(QMap<QString, Project*>* projects);

        void joinProject(const Project& project);
        void leaveProject(const Project& project);

    private:
        int id;
        QString* name;
        QMap<QString, Project*>* enrolled;
        QMap<QString, Project*>* available;
};

#endif // REALSTUDENT_H
