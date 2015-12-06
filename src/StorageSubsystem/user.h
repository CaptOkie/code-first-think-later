#ifndef USER_H
#define USER_H

#include<QString>

/**
 * @brief The User class. Abstract class for Users.
 */
class User
{
    public:
        User();
        virtual ~User();

        /**
         * @brief getQuestions
         * @return A map of Questions indexed by their ids.
         */
        virtual int getId() const = 0;
        /**
         * @brief getEnrolledProjects
         * @return A map of Projects indexed by their name that the Student is enrolled in.
         */
        virtual const QString& getName() const = 0;
};

#endif // USER_H
