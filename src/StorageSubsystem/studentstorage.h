#ifndef STUDENTSTORAGE_H
#define STUDENTSTORAGE_H

#include <QtSql>
#include <QMap>

#include "student.h"

/**
 * @brief The StudentStorage class. Access information in the database pertaining to a specific Student.
 *        Such as what Projects a Student is enrolled in.
 */
class StudentStorage
{
    public:
        /**
         * @brief StudentStorage The constructor.
         * @param db Database connection StudentStorage uses to communicate with database.
         */
        StudentStorage(QSqlDatabase& db);
        StudentStorage(StudentStorage& other);
        ~StudentStorage();

        /**
         * @brief getQuestions
         * @param student The Student.
         * @return Returns the Questions a Student can responed to.
         */
        QMap<int, Question*>* getQuestions(const Student& student);
        /**
         * @brief getEnrolledProjects
         * @param student The Student
         * @return Return the Projects a Student is enrolled in.
         */
        QMap<QString, Project*>* getEnrolledProjects(const Student& student);
        /**
         * @brief getAvailableProjects
         * @param student The Student
         * @return Return the Projects a Student can enroll.
         */
        QMap<QString, Project*>* getAvailableProjects(const Student& student);

        /**
         * @brief joinProject Joins a Student into a given Project.
         * @param student The Student.
         * @param project The Project.
         * @return Whether it was successful or not.
         */
        bool joinProject(const Student& student, const Project& project);
        /**
         * @brief leaveProject Unenrolls a Student from a Project.
         * @param student The Student.
         * @param project The Project.
         * @return Whether it was successful or not.
         */
        bool leaveProject(const Student& student, const Project& project);

    private:
        /**
         * @brief db The database connection.
         */
        QSqlDatabase& db;
};

#endif // STUDENTSTORAGE_H
