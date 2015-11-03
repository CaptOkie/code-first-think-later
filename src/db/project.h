#ifndef PROJECT_H
#define PROJECT_H

#include <QString>

#include "groupsize.h"

/**
 * @brief The Project class
 *
 * Stores information about a project.
 */
class Project
{
    public:
        /**
         * @brief Project Creates a new instance, which claims ownership of, and responsibility for deleting, pointers.
         * @param name The name of the project.
         * @param groupSize The group size constraints on the project.
         */
        Project(QString* name, GroupSize* groupSize);

        /**
         * @brief Project Creates a new instance.
         * @param name The name of the project.
         * @param groupSize The group size constraints on the project.
         */
        Project(const QString& name, const GroupSize& groupSize);

        /**
         * @brief Project Creates a new instance.
         * @param copy The Project to copy.
         */
        Project(const Project& copy);

        ~Project();

        /**
         * @brief getName
         * @return The name of the project.
         */
        const QString& getName() const;

        /**
         * @brief getGroupSize
         * @return The GroupSize constraints on the Project.
         */
        const GroupSize& getGroupSize() const;

    private:
        QString* name;        // The name of the project
        GroupSize* groupSize; // The group size constraint
};

#endif // PROJECT_H
