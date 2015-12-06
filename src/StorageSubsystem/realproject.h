#ifndef REALPROJECT_H
#define REALPROJECT_H

#include "project.h"

/**
 * @brief The RealProject class. The Project class that holds the state for the Project such as the the Groups
 *        and enrolled Students. Inherits from Project.
 */
class RealProject : public Project
{
    public:
        /**
         * @brief RealProject The constructor.
         * @param id The id of the Project.
         * @param name The name.
         * @param minGroupSize The min group size.
         * @param maxGroupSize The max group size.
         */
        RealProject(int id, QString* name, int minGroupSize, int maxGroupSize);
        ~RealProject();

        /**
         * @brief getId
         * @return Return the id.
         */
        virtual int getId() const;
        /**
         * @brief getName
         * @return Returns the name.
         */
        virtual const QString& getName() const;
        /**
         * @brief getMinGroupSize
         * @return Returns the min group size.
         */
        virtual int getMinGroupSize() const;
        /**
         * @brief getMaxGroupSize
         * @return Returns the max Group size.
         */
        virtual int getMaxGroupSize() const;

        /**
         * @brief setName Sets the name of the Project.
         * @param newName The name.
         * @return Whether it was successful or not.
         */
        virtual bool setName(QString* newName);
        /**
         * @brief setMinGroupSize Sets the min group size of the Project.
         * @param newMinGroupSize The size.
         * @return Whether it was successful or not.
         */
        virtual bool setMinGroupSize(int newMinGroupSize);
        /**
         * @brief setMaxGroupSize Sets the max group size of the Project.
         * @param newMaxGroupSize The size.
         * @return Whether it was successful or not.
         */
        virtual bool setMaxGroupSize(int newMaxGroupSize);

        /**
         * @brief getStudents
         * @return A map of Students indexed by their ids that are enrolled in the Project.
         */
        const QMap<int, Student*>& getStudents() const;
        /**
         * @brief getGroups
         * @return A map of Groups indexed by their ids of the Groups of the Project.
         */
        const QMap<int, Group*>& getGroups() const;

        /**
         * @brief setStudents Sets the Students to be enrolled in the Project.
         * @param students Map of Students indexed by their ids.
         */
        void setStudents(QMap<int, Student*>* students);

        /**
         * @brief setGroups Sets the Groups of the Project.
         * @param groups List of Groups.
         * @return whether it was successful or not.
         */
        bool setGroups(QList<Group*>& groups);
        /**
         * @brief setGroups Sets the Groups of the Project.
         * @param groups Map of Groups indexed by their ids.
         * @return whether it was successful or not.
         */
        bool setGroups(QMap<int, Group*>* groups);

    private:
        /**
         * @brief id id of the Project.
         */
        int id;
        /**
         * @brief name The name of the Project.
         */
        QString* name;
        /**
         * @brief minGroupSize The min group size.
         */
        int minGroupSize;
        /**
         * @brief maxGroupSize The max group size.
         */
        int maxGroupSize;

        /**
         * @brief students The enrolled Students.
         */
        QMap<int, Student*>* students;
        /**
         * @brief groups The groups.
         */
        QMap<int, Group*>*   groups;

        // Private functions for dealing with deleting pointers.
        void clearStudents();
        void clearGroups();
};

#endif // REALPROJECT_H
