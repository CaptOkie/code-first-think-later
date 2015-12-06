#ifndef PROXYADMIN_H
#define PROXYADMIN_H

#include "admin.h"
#include "realadmin.h"
#include "adminstorage.h"

/**
 * @brief The ProxyAdmin class. The Admin object that manages loading from storage and setting in the RealAdmin.
 *        Inherits from Admin.
 */
class ProxyAdmin : public Admin
{
    public:
        /**
         * @brief ProxyAdmin The constructor for ProxyAdmin
         * @param id The id of the admin in the database.
         * @param name The name of the admin.
         * @param storage The storage object used to communicate with the database.
         */
        ProxyAdmin(int id, QString* name, AdminStorage* storage);
        ~ProxyAdmin();

        /**
         * @brief getId
         * @return The id of the admin.
         */
        virtual int getId() const;
        /**
         * @brief getName
         * @return The name of the admin.
         */
        virtual const QString& getName() const;

        /**
         * @brief getProjects
         * @return A map of the Projects indexed by their name.
         */
        virtual QMap<QString, Project*>& getProjects();
        /**
         * @brief getProjects
         * @return A map of the Projects indexed by their name.
         */
        const QMap<QString, Project*>& getProjects() const;

        /**
         * @brief deleteProject Remove a given Project.
         * @param project The Project.
         * @return The Project* of the removed Project.
         */
        Project* deleteProject(const Project& project);
        /**
         * @brief addProject Adding a given Project.
         * @param project The Project.
         * @return Whether the addition of a new Project was successful or not.
         */
        bool addProject(Project& project);

    private:
        /**
         * @brief realAdmin The Admin object to hold the state.
         */
        RealAdmin* realAdmin;
        /**
         * @brief storage The storage which is interacted with.
         */
        AdminStorage* storage;
};

#endif // PROXYADMIN_H
