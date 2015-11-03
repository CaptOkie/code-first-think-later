#ifndef USER_H
#define USER_H

#include <QString>

/**
 * @brief The User class
 *
 * Stores information about the User.
 */
class User
{
    public:
        /**
         * @brief The Type enum
         *
         * The different types of users.
         */
        enum Type {
            STUDENT, ADMIN
        };

    public:
        /**
         * @brief User Creates a new instance, which claims ownership of, and responsibility for deleting, pointers.
         * @param id The user's ID.
         * @param type The user's type.
         * @param name The user's name.
         */
        User(int id, Type type, QString* name);

        /**
         * @brief User Creates a new instance.
         * @param id The user's ID.
         * @param type The user's type.
         * @param name The user's name.
         */
        User(int id, Type type, const QString& name);

        /**
         * @brief User Creates a new instance.
         * @param copy The user to copy.
         */
        User(const User& copy);

        ~User();

        /**
         * @brief getId
         * @return The user's ID.
         */
        int      getId() const;

        /**
         * @brief getType
         * @return The user's type.
         */
        Type     getType() const;

        /**
         * @brief getName
         * @return The user's name.
         */
        QString& getName() const;

    private:
        int      id;   // The user's ID
        Type     type; // The user's type
        QString* name; // The user's name
};

#endif // USER_H
