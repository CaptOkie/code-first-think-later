#ifndef STUDENT_H
#define STUDENT_H

#include <QMap>

#include "user.h"
#include "question.h"

class Project;

/**
 * @brief The Student class. Abstract class for the Student. Inherits from User.
 */
class Student: public User
{
    public:
        Student();
        virtual ~Student();

        /**
         * @brief getQuestions
         * @return A map of Questions indexed by their ids.
         */
        virtual const QMap<int, Question*>& getQuestions() const = 0;
        /**
         * @brief getEnrolledProjects
         * @return A map of Projects indexed by their name that the Student is enrolled in.
         */
        virtual const QMap<QString, Project*>& getEnrolledProjects() const = 0;
        /**
         * @brief getAvailableProject
         * @return A map of Projects indexed by their name that is available for the Student to enroll in.
         */
        virtual const QMap<QString, Project*>& getAvailableProject() const = 0;

        /**
         * @brief joinProject Enrolls the Student in the given Project.
         * @param project The Project.
         * @return Whether it was successful or not.
         */
        virtual bool joinProject(const Project& project) = 0;
        /**
         * @brief leaveProject Unenrolls the Student from the given Project.
         * @param project The Project.
         * @return Whether it was successful or not.
         */
        virtual bool leaveProject(const Project& project) = 0;
};

#endif // STUDENT_H
