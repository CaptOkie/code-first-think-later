#ifndef PROJECTSTORAGE_H
#define PROJECTSTORAGE_H

#include <QtSql>
#include <QMap>
#include <QList>

#include "project.h"
#include "student.h"

/**
 * @brief The ProjectStorage class. Access information in the database pertaining to a specific project.
 *        Such as what Students are enrolled in the project and updating Project fields.
 */
class ProjectStorage
{
    public:
        /**
         * @brief ProjectStorage Constructor
         * @param db Database connection ProjectStorage uses to communicate with database.
         */
        ProjectStorage(QSqlDatabase& db);
        /**
         * @brief ProjectStorage Copy Constructor.
         * @param other The ProjectStorage object to copy.
         */
        ProjectStorage(const ProjectStorage& other);
        ~ProjectStorage();

        /**
         * @brief updateProject Updates the given Project.
         * @param project The project to update.
         * @return A bool on whether the database was successful or not.
         */
        bool updateProject(const Project& project);

        /**
         * @brief getStudents Get the Students enrolled to the given project.
         * @param project The project
         * @return A map indexed by the Student's id of all the Students enrolled in the project.
         */
        QMap<int, Student*>* getStudents(const Project& project);
        /**
         * @brief getGroups Get the Groups that the Students are divided into for the given Project.
         * @param project The Project.
         * @return A map indexed by the Group's id of all the groups of that project.
         *         If there are Students present who are not in a group, they belong to the Group with id = -1.
         */
        QMap<int, Group*>* getGroups(const Project& project);

        /**
         * @brief setGroups Stores the Groups of a given Project in the database.
         * @param project The Project.
         * @param groups The list of Groups which have not been assigned an id yet to be stored.
         * @return A map indexed by the Group's id of all the groups of that project.
         */
        QMap<int, Group*>* setGroups(const Project& project, const QList<Group*>& groups);
        /**
         * @brief setGroups Stores the Groups of a given Project in the database.
         * @param project The Project.
         * @param groups A map indexed by the Group's id of all the groups of that Project.
         * @return Whether the database was successful or not.
         */
        bool setGroups(const Project& project, const QMap<int, Group*>& groups);

    private:
        /**
         * @brief db The database connection.
         */
        QSqlDatabase& db;
};

#endif // PROJECTSTORAGE_H
