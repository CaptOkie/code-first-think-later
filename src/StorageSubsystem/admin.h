#ifndef ADMIN_H
#define ADMIN_H

#include <QString>
#include <QMap>

#include "user.h"
#include "project.h"

class Admin : public User
{
    public:
        Admin(int id, QString* name);
        virtual ~Admin();

        virtual const QMap<QString, Project*>& getProjects() const = 0;
        virtual QMap<QString, Project*>& getProjects() = 0;

        virtual Project* deleteProject(const Project& project) = 0;
        virtual bool addProject(Project& project) = 0;
};

#endif // ADMIN_H
