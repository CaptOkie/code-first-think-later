#ifndef REALADMIN_H
#define REALADMIN_H

#include "admin.h"

class RealAdmin : public Admin
{
    public:
        RealAdmin(int id, QString* name);
        ~RealAdmin();

        virtual int getId() const;
        virtual const QString& getName() const;

        virtual QMap<QString, Project*>& getProjects();
        const QMap<QString, Project*>& getProjects() const;
        bool hasProjects() const;

        void setProjects(QMap<QString, Project*>* projects);

        Project* deleteProject(const Project& project);
        bool addProject(Project& project);

    private:
        int id;
        QString* name;
        QMap<QString, Project*>* projects;

};

#endif // REALADMIN_H
