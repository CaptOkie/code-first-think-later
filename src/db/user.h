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
        User(int, Type, QString*);
        ~User();

        int      getId();
        Type     getType();
        QString& getName();


    private:
        int      id;
        Type     type;
        QString* name;
};

#endif // USER_H
