#ifndef USER_H
#define USER_H

#include<QString>

class User
{
    public:
        User();
        ~User();

        int getId() const;
        const QString& getName() const;

    protected:
        int id;
        QString* name;
};

#endif // USER_H
