#ifndef STUDENTSTORAGE_H
#define STUDENTSTORAGE_H

#include <QtSql>
#include <QMap>

#include "student.h"

class StudentStorage
{
    public:
        StudentStorage(QSqlDatabase& db);
        ~StudentStorage();

        QMap<int, Question*>* getQuestions(const Student& student);
        QMap<QString, Project*>* getEnrolledProjects(const Student& student);
        QMap<QString, Project*>* getAvailableProjects(const Student& student);

        void joinProject(const Student& student, const Project& project);
        void leaveProject(const Student& student, const Project& project);

    private:
        QSqlDatabase& db;
};

#endif // STUDENTSTORAGE_H
