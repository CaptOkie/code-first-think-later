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
        User(int, Type, const QString&);
        User(const User&);
        ~User();

        int      getId() const;
        Type     getType() const;
        QString& getName() const;


    private:
        int      id;
        Type     type;
        QString* name;
};

#endif // USER_H
