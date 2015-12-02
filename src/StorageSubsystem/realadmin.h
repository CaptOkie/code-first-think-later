#ifndef REALADMIN_H
#define REALADMIN_H

#include "admin.h"

class RealAdmin : public Admin
{
    public:
        RealAdmin(int id, QString* name);
        ~RealAdmin();

        const QMap<QString, Project*>& getProjects() const;
        virtual QMap<QString, Project*>& getProjects();
        bool hasProjects() const;

        void setProjects(QMap<QString, Project*>* projects);

        void deleteProject(const Project& project);
        void addProject(const Project& project);
        void updateProject(const Project& project);

    private:
        QMap<QString, Project*>* projects;

};

#endif // REALADMIN_H
