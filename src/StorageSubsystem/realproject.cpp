#include "realproject.h"

RealProject::RealProject(int id, QString* name, int minGroupSize, int maxGroupSize)
    : Project(id, name, minGroupSize, maxGroupSize)
{ }

RealProject::~RealProject()
{ }

const QMap<int, Student*>& RealProject::getStudents() const
{

}

const QMap<int, Group*>& RealProject::getGroups() const
{

}

void RealProject::setGroups(const QList<Group*>& groups)
{

}

void RealProject::setGroups(const QMap<int, Group*>& groups)
{

}
