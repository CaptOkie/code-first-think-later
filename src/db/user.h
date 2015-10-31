#ifndef USER_H
#define USER_H

#include <QString>

class User
{
    public:
        enum Type {
            STUDENT, ADMIN
        };

    public:
        User(Type, QString*);
        ~User();

        Type getType();

    private:
        Type     type;
        QString* name;
};

#endif // USER_H
