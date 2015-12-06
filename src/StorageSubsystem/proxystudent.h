#ifndef PROXYSTUDENT_H
#define PROXYSTUDENT_H

#include "student.h"
#include "realstudent.h"
#include "studentstorage.h"
#include "indicator.h"
#include "project.h"

/**
 * @brief The ProxyStudent class. The Student class which manages loading from the storage.
 *        Inherits from Student.
 */
class ProxyStudent : public Student
{
    public:
        /**
         * @brief ProxyStudent The constructor.
         * @param id The id of the Student.
         * @param name The name of the Student.
         * @param storage The storage that is interacted with.
         */
        ProxyStudent(int id, QString* name, StudentStorage* storage);
        ~ProxyStudent();

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
         * @brief hasEnrolled Indicates whether the enrolled Projects have been loaded from storage or not.
         */
        Indicator* hasEnrolled;
        /**
         * @brief hasAvailable Indicates whether the available Projects have been loaded from storage or not.
         */
        Indicator* hasAvailable;
        /**
         * @brief hasQuestions Indicates whether the Questions have been loaded from storage or not.
         */
        Indicator* hasQuestions;
        /**
         * @brief realStudent The Student object with the state.
         */
        RealStudent* realStudent;
        /**
         * @brief storage The storage interacted with.
         */
        StudentStorage* storage;
};

#endif // PROXYSTUDENT_H
