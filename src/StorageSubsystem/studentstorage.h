#ifndef STUDENTSTORAGE_H
#define STUDENTSTORAGE_H

#include <QtSql>
#include <list>

#include "student.h"

class StudentStorage
{
public:
    StudentStorage();
    ~StudentStorage();

    std::list<Question> getQuestions(Student);
    std::list<Project> getEnrolledProjects(Student);
    std::list<Project> getAvailableProjects(Student);
    void joinProject(Student, Project);
    void leaveProject(Student, Project);

private:
    QSqlDatabase db;
    //void setupDB();
    //void populateDatabase();
};

#endif // STUDENTSTORAGE_H
