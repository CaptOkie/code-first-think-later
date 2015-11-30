#ifndef PROXYADMIN_H
#define PROXYADMIN_H

#include "admin.h"
#include "realadmin.h"

class ProxyAdmin : public Admin
{
    public:
        ProxyAdmin(int id, QString* name);
        ~ProxyAdmin();

        const QMap<QString, Project>& getProjects() const;
        QMap<QString, Project>& getProjects();

        void deleteProject(const Project& project);
        void addProject(const Project& project);

    private:
        RealAdmin* realAdmin;
};

#endif // PROXYADMIN_H
