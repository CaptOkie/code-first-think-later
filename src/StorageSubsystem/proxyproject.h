#ifndef PROXYPROJECT_H
#define PROXYPROJECT_H

#include "project.h"
#include "realproject.h"
#include "projectstorage.h"
#include "indicator.h"

/**
 * @brief The ProxyProject class. The Project class which manages loading from the storage.
 *        Inherits from Project.
 */
class ProxyProject : public Project
{
    public:
        /**
         * @brief ProxyProject Constructor for ProxyProject.
         * @param id The id of a porject in the database.
         * @param name The name of the project.
         * @param minGroupSize The minimum group size of a Project.
         * @param maxGroupSize The maximum group size of a Project.
         * @param storage The the storage ProxyProject interacts with.
         */
        ProxyProject(int id, QString* name, int minGroupSize, int maxGroupSize, ProjectStorage* storage);
        ProxyProject(const Project& other, ProjectStorage* storage);
        ~ProxyProject();

        /**
         * @brief getId
         * @return The id of the Project.
         */
        virtual int getId() const;
        /**
         * @brief getName
         * @return The name of the Project.
         */
        virtual const QString& getName() const;
        /**
         * @brief getMinGroupSize
         * @return The min group size.
         */
        virtual int getMinGroupSize() const;
        /**
         * @brief getMaxGroupSize
         * @return The max group size.
         */
        virtual int getMaxGroupSize() const;

        /**
         * @brief setName Sets the name of a Project
         * @param newName The name.
         * @return Whether the setting was successful or not.
         */
        virtual bool setName(QString* newName);
        /**
         * @brief setMinGroupSize Sets the min group size of the Project.
         * @param newMinGroupSize The size.
         * @return Whether the setting was successful or not.
         */
        virtual bool setMinGroupSize(int newMinGroupSize);
        /**
         * @brief setMaxGroupSize Sets the max group size of the Project.
         * @param newMaxGroupSize The size.
         * @return Whether the setting was successful or not.
         */
        virtual bool setMaxGroupSize(int newMaxGroupSize);

        /**
         * @brief getStudents
         * @return A map of Students indexed by their ids that are enrolled in the Project.
         */
        virtual const QMap<int, Student*>& getStudents() const;
        /**
         * @brief getGroups
         * @return A map of Groups indexed by their ids of a Project.
         */
        virtual const QMap<int, Group*>& getGroups() const;

        /**
         * @brief setGroups
         * @param groups List of Groups to set as the groups of the Project.
         * @return Whether it was successful or not.
         */
        virtual bool setGroups(QList<Group*>& groups);
        /**
         * @brief setGroups
         * @param groups A map of Groups indexed by their ids to be set for a Project.
         * @return Whether it was successful or not.
         */
        virtual bool setGroups(QMap<int, Group*>* groups);

    private:
        Indicator* hasLoaded;
        RealProject* realProject;
        ProjectStorage* storage;
};

#endif // PROXYPROJECT_H
