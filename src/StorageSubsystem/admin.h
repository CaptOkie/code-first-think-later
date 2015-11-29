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

        virtual const QMap<QString, Project>& getProjects() const;
        virtual QMap<QString, Project>& getProjects();

        virtual void deleteProject(const Project& project);
        virtual void addProject(const Project& project);
};

#endif // ADMIN_H
