#ifndef USER_H
#define USER_H

#include <string>

class User
{
public:
    User();
    ~User();

protected:
    int id;
    std::string name;
};

#endif // USER_H
