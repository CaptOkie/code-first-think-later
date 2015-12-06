#ifndef ADMINSTORAGE_H
#define ADMINSTORAGE_H

#include <QtSql>
#include <QMap>

#include "admin.h"
#include "storage.h"

class AdminStorage
{
    public:
        /**
         * @brief AdminStorage Constructor
         * @param db Database connection AdminStorage uses to communicate with database.
         */
        AdminStorage(QSqlDatabase& db);
        ~AdminStorage();

        /**
         * @brief getProjects retrieves all the projects from the database.
         * @return A map of the projects indexed by their names.
         */
        QMap<QString, Project*>* getProjects();

        /**
         * @brief deleteProject Removes the given project from the database.
         * @param project The project to remove from the database.
         * @return A bool on whether the database was successful or not.
         */
        bool deleteProject(const Project& project);
        /**
         * @brief addProject Adds the given project to the database.
         * @param project The project to add to the database.
         * @return The Project* of the newly added project, or NULL if the database was unsuccessful.
         */
        Project* addProject(const Project& project);

    private:
        /**
         * @brief db the database connection.
         */
        QSqlDatabase& db;
};

#endif // ADMINSTORAGE_H
