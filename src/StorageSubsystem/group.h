#ifndef GROUP_H
#define GROUP_H

#include <QMap>

#include "student.h"

/**
 * @brief The Group class. A group of Students belonging to a Project.
 */
class Group
{
    public:
        /**
         * @brief Group The constructor.
         * @param id The id of the Group.
         * @param students The map of Students.
         */
        Group(int id, QMap<int, Student*>* students);
        Group();
        ~Group();

        /**
         * @brief getId
         * @return The id of the Group.
         */
        int getId() const;

        /**
         * @brief setId Set the id of the Group.
         * @param id The id.
         */
        void setId(int id);

        /**
         * @brief getStudents
         * @return A map of Students indexed by their ids that belong to the Group.
         */
        QMap<int, Student*>& getStudents();
        /**
         * @brief getStudents
         * @return A map of Students indexed by their ids that belong to the Group.
         */
        const QMap<int, Student*>& getStudents() const;

    private:
        /**
         * @brief id The id.
         */
        int id;
        /**
         * @brief students THe collection of Students.
         */
        QMap<int, Student*>* students;
};

#endif // GROUP_H
