#include "realadmin.h"

RealAdmin::RealAdmin(int id, QString* name)
    : Admin(id, name)
{ }

RealAdmin::~RealAdmin()
{ }

const QMap<QString, Project>& RealAdmin::getProjects() const
{

}

QMap<QString, Project>& RealAdmin::getProjects()
{

}

void RealAdmin::deleteProject(const Project& project)
{

}

void RealAdmin::addProject(const Project& project)
{

}
