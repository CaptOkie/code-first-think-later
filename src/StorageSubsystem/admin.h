#ifndef ADMIN_H
#define ADMIN_H

#include <QString>
#include <QMap>

#include "user.h"
#include "project.h"

/**
 * @brief The Admin class. Abstract class for the Admin. Inherits from Admin.
 */
class Admin : public User
{
    public:
        Admin();
        virtual ~Admin();

        /**
         * @brief getProjects
         * @return A map of the Projects indexed by their name.
         */
        virtual const QMap<QString, Project*>& getProjects() const = 0;
        /**
         * @brief getProjects
         * @return A map of the Projects indexed by their name.
         */
        virtual QMap<QString, Project*>& getProjects() = 0;

        /**
         * @brief deleteProject Remove a given Project.
         * @param project The Project.
         * @return The Project* of the removed Project.
         */
        virtual Project* deleteProject(const Project& project) = 0;
        /**
         * @brief addProject Adding a given Project.
         * @param project The Project.
         * @return Whether the addition of a new Project was successful or not.
         */
        virtual bool addProject(Project& project) = 0;
};

#endif // ADMIN_H
