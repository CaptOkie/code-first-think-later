#ifndef STORAGE_H
#define STORAGE_H

#include <QtSql>

#include "user.h"
#include "project.h"
#include "response.h"
#include "question.h"
#include <QList>

/**
 * @brief The Storage class The class used for connection to the database.
 */
class Storage
{
    public:
        Storage();
        ~Storage();

        /**
         * @brief addProject Adds a new project to the database.
         * @param project The Project object to be added to the database.
         * @return
         */
        bool addProject(Project& project);

        /**
         * @brief updateProject Updates attributes of a current project.
         * @param name The current name of the project.
         */
        void updateProject(Project& project, QString& name);

        /**
         * @brief removeProject Removes a given project from the database.
         * @param project The name of the project to remove.
         */
        void removeProject(QString& project);

        /**
         * @brief enrollStudent Stores the enrollment of a student to a project in the database.
         * @param project The name of the project.
         * @param stuId The id of the student.
         */
        void enrollStudent(QString& project, int stuId);

        /**
         * @brief unenrollStudent Stores the unenrollment of a student of a project in the database.
         * @param project The name of the project.
         * @param stuId The id of the student.
         */
        void unenrollStudent(QString& project, int stuId);

        /**
         * @brief updateResponse Stores a student's updated response to a profile question into the database.
         * @param respons The response object.
         */
        void updateResponse(const Response& response);

        /**
         * @brief updateResponses Stores an updated list of responses  to the database.
         * @param responses List of Response objects.
         */
        void updateResponses(const QList<Response>& responses);

        /**
         * @brief getUser Retrieves a User from the database based on a given id.
         * @param id The id to determine the User
         * @param user The returned User object
         * @return
         */
        bool getUser(int id, User** user);

        /**
         * @brief getProjects Retrieves a list of projects from the database.
         * @param projects The returned list of projects.
         */
        void getProjects(QList<Project>** projects);

        /**
         * @brief getProjects Returns two lists of project names: One for which the student is enrolled,
         *                    and one for which the student is not.
         * @param enrolled The returned list of project names for which the student is enrolled.
         * @param available The returned list of project names for which the student is not enrolled.
         * @param student The student.
         */
        void getProjects(QList<QString>** enrolled, QList<QString>** available, User& student);

        /**
         * @brief getProjects Retrieves a list of Projects from the database based on a given project name.
         * @param projects The returned list of Projects.
         * @param name The name of the projects.
         */
        void getProjects(QList<Project>** projects, QString& name);

        /**
         * @brief getResponses Retrieves a list of Questions along with the Responses given by a Student.
         * @param questions The returned list of Questions.
         * @param stuId The student.
         */
        void getResponses(QList<Question>& questions, int stuId);

    private:
        /**
         * @brief db QSqlDatabase object used for connecting and directly interacting with the database.
         */
        QSqlDatabase db;

        /**
         * @brief setupDB Intializes the database.
         */
        void setupDB();

        /**
         * @brief populateDatabase USED PURELY FOR DEBUGGING. Populates the database with information.
         */
        void populateDatabase();
};

#endif // STORAGE_H
