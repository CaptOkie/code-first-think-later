#ifndef USER_H
#define USER_H

#include<QString>

class User
{
    public:
        User();
        virtual ~User();

        virtual int getId() const = 0;
        virtual const QString& getName() const = 0;
};

#endif // USER_H
