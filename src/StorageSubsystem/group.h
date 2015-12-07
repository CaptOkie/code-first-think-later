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
        Group(const Group& other);
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

        /**
         * @brief getMatch
         * @return Gets the match percentage of the group.
         */
        int getMatch() const;

        /**
         * @brief setMatch Sets the match percentage of the group.
         * @param match The match percentage of the group.
         */
        void setMatch(int match);

    private:
        /**
         * @brief id The id.
         */
        int id;
        /**
         * @brief students The collection of Students.
         */
        QMap<int, Student*>* students;
        /**
         * @brief match The match percentage of the group.
         */
        int match;
};

#endif // GROUP_H
