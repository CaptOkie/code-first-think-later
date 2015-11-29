#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include <string>

class Admin
{
public:
    Admin();
    void getProjects(); //Temporary
    void deleteProject(); //Temporary
    void addProject(); //Temporary

protected:
    std::string name;
};

#endif // ADMIN_H
