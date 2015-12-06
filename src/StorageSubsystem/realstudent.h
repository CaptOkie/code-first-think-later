#ifndef REALSTUDENT_H
#define REALSTUDENT_H

#include "student.h"

/**
 * @brief The RealStudent class. The Student class that holds the state for the Student such as the Student's
 *        enrolled Projects. Inherits from Student.
 */
class RealStudent : public Student
{
    public:
        /**
         * @brief RealStudent The constructor.
         * @param id The id of the Student.
         * @param name The name of the Student.
         */
        RealStudent(int id, QString* name);
        ~RealStudent();

        /**
         * @brief getId
         * @return The id.
         */
        virtual int getId() const;
        /**
         * @brief getName
         * @return The name of the Student.
         */
        virtual const QString& getName() const;

        /**
         * @brief getQuestions
         * @return A map of Questions indexed by their ids.
         */
        const QMap<int, Question*>& getQuestions() const;
        /**
         * @brief getEnrolledProjects
         * @return A map of Projects indexed by their name that the Student is enrolled in.
         */
        const QMap<QString, Project*>& getEnrolledProjects() const;
        /**
         * @brief getAvailableProject
         * @return A map of Projects indexed by their name that is available for the Student to enroll in.
         */
        const QMap<QString, Project*>& getAvailableProject() const;

        /**
         * @brief setQuestions Sets the questions the student can responsed to.
         * @param questions The Questions.
         */
        void setQuestions(QMap<int, Question*>* questions);

        /**
         * @brief setEnrolledProjects Sets the Projects to the Student's enrolled Projects.
         * @param projects The Projects.
         */
        void setEnrolledProjects(QMap<QString, Project*>* projects);
        /**
         * @brief setAvailableProjects Sets the Projects to the Student's available Projects.
         * @param projects The Projects.
         */
        void setAvailableProjects(QMap<QString, Project*>* projects);

        /**
         * @brief joinProject Enrolls the Student in the given Project.
         * @param project The Project.
         * @return Whether it was successful or not.
         */
        bool joinProject(const Project& project);
        /**
         * @brief leaveProject Unenrolls the Student from the given Project.
         * @param project The Project.
         * @return Whether it was successful or not.
         */
        bool leaveProject(const Project& project);

    private:
        /**
         * @brief id The id of the Student
         */
        int id;
        /**
         * @brief name The name of the Student
         */
        QString* name;
        /**
         * @brief enrolled The enrolled Projects.
         */
        QMap<QString, Project*>* enrolled;
        /**
         * @brief available The available Projects.
         */
        QMap<QString, Project*>* available;
        /**
         * @brief questions The Questions.
         */
        QMap<int, Question*>* questions;

    private:
        // Private functions for dealing with deleting pointers.
        void deleteProjects(QMap<QString, Project*>* projects);
        void deleteQuestions();
};

#endif // REALSTUDENT_H
