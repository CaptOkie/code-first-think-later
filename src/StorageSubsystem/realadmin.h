#ifndef REALADMIN_H
#define REALADMIN_H

#include "admin.h"

class RealAdmin : public Admin
{
    public:
        RealAdmin(int id, QString* name);
        ~RealAdmin();

        const QMap<QString, Project>& getProjects() const;
        QMap<QString, Project>& getProjects();

        void deleteProject(const Project& project);
        void addProject(const Project& project);

};

#endif // REALADMIN_H
