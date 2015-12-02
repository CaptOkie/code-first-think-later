#ifndef REALADMIN_H
#define REALADMIN_H

#include "admin.h"

class RealAdmin : public Admin
{
    public:
        RealAdmin(int id, QString* name);
        ~RealAdmin();

        virtual QMap<QString, Project*>& getProjects();
        const QMap<QString, Project*>& getProjects() const;
        bool hasProjects() const;

        void setProjects(QMap<QString, Project*>* projects);

        Project* deleteProject(const Project& project);
        bool addProject(Project& project);

    private:
        QMap<QString, Project*>* projects;

};

#endif // REALADMIN_H
