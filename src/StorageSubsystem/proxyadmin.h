#ifndef PROXYADMIN_H
#define PROXYADMIN_H

#include "admin.h"
#include "realadmin.h"
#include "adminstorage.h"

class ProxyAdmin : public Admin
{
    public:
        ProxyAdmin(int id, QString* name, AdminStorage* storage);
        ~ProxyAdmin();

        virtual int getId() const;
        virtual const QString& getName() const;

        virtual QMap<QString, Project*>& getProjects();
        const QMap<QString, Project*>& getProjects() const;

        Project* deleteProject(const Project& project);
        bool addProject(Project& project);

    private:
        RealAdmin* realAdmin;
        AdminStorage* storage;
};

#endif // PROXYADMIN_H
