#ifndef PROJECT_H
#define PROJECT_H

#include <QString>
#include <QMap>
#include <QList>
#include <QString>

#include "group.h"

class Student;

/**
 * @brief The Project class. The abstract class for Project.
 */
class Project
{
    public:
        Project();
        virtual ~Project();

        /**
         * @brief getId
         * @return Return the id.
         */
        virtual int getId() const = 0;
        /**
         * @brief getName
         * @return Returns the name.
         */
        virtual const QString& getName() const = 0;
        /**
         * @brief getMinGroupSize
         * @return Returns the min group size.
         */
        virtual int getMinGroupSize() const = 0;
        /**
         * @brief getMaxGroupSize
         * @return Returns the max Group size.
         */
        virtual int getMaxGroupSize() const = 0;

        /**
         * @brief setName Sets the name of the Project.
         * @param newName The name.
         * @return Whether it was successful or not.
         */
        virtual bool setName(QString* newName) = 0;
        /**
         * @brief setMinGroupSize Sets the min group size of the Project.
         * @param newMinGroupSize The size.
         * @return Whether it was successful or not.
         */
        virtual bool setMinGroupSize(int newMinGroupSize) = 0;
        /**
         * @brief setMaxGroupSize Sets the max group size of the Project.
         * @param newMaxGroupSize The size.
         * @return Whether it was successful or not.
         */
        virtual bool setMaxGroupSize(int newMaxGroupSize) = 0;

        /**
         * @brief getStudents
         * @return A map of Students indexed by their ids that are enrolled in the Project.
         */
        virtual const QMap<int, Student*>& getStudents() const = 0;
        /**
         * @brief getGroups
         * @return A map of Groups indexed by their ids of the Groups of the Project.
         */
        virtual const QMap<int, Group*>& getGroups() const = 0;

        /**
         * @brief setGroups Sets the Groups of the Project.
         * @param groups List of Groups.
         * @return whether it was successful or not.
         */
        virtual bool setGroups(QList<Group*>& groups) = 0;
        /**
         * @brief setGroups Sets the Groups of the Project.
         * @param groups Map of Groups indexed by their ids.
         * @return whether it was successful or not.
         */
        virtual bool setGroups(QMap<int, Group*>* groups) = 0;
};

#endif // PROJECT_H
