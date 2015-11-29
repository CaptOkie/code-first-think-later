#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <list>

#include "user.h"
#include "project.h"

class Admin
{
public:
    Admin();
    ~Admin();

    std::list<Project> getProjects();
    void deleteProject(Project);
    void addProject(Project);
};

#endif // ADMIN_H
