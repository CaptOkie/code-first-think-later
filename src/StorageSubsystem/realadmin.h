#ifndef REALADMIN_H
#define REALADMIN_H

#include "admin.h"

/**
 * @brief The RealAdmin class. The Admin class that holds the state for the Admin such as the the actual map of
 *        Projects. Inherits from Admin.
 */
class RealAdmin : public Admin
{
    public:
        /**
         * @brief RealAdmin The constructor.
         * @param id The id of the Admin.
         * @param name The name of the Admin.
         */
        RealAdmin(int id, QString* name);
        ~RealAdmin();

        /**
         * @brief getId
         * @return The id.
         */
        virtual int getId() const;
        /**
         * @brief getName
         * @return The name.
         */
        virtual const QString& getName() const;

        /**
         * @brief getProjects
         * @return The map of all Projects indexed by their names.
         */
        virtual QMap<QString, Project*>& getProjects();
        /**
         * @brief getProjects
         * @return The map of all Projects indexed by their names.
         */
        const QMap<QString, Project*>& getProjects() const;

        void setProjects(QMap<QString, Project*>* projects);

        /**
         * @brief deleteProject Removes the given Project.
         * @param project The Project.
         * @return The Projet* of the removed Project.
         */
        Project* deleteProject(const Project& project);
        /**
         * @brief addProject Adds the given Project.
         * @param project The Project.
         * @return Whether it was successful or not.
         */
        bool addProject(Project& project);

    private:
        int id;
        QString* name;
        QMap<QString, Project*>* projects;

};

#endif // REALADMIN_H
