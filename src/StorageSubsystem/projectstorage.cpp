#include "storage.h"
#include "projectstorage.h"
#include "proxystudent.h"

ProjectStorage::ProjectStorage(QSqlDatabase& db)
    : db(db)
{ }

ProjectStorage::ProjectStorage(const ProjectStorage& other)
    : db(other.db)
{ }

ProjectStorage::~ProjectStorage()
{
    if(db.isOpen())
        db.close();
}

bool ProjectStorage::updateProject(const Project &project)
{
    bool result;
    db.open();

    QSqlQuery update(db);
    update.prepare("UPDATE " PRO_TABLE
                   " SET " PRO_NAME_COL " = :name, " PRO_MIN_GRP_COL " = :min, " PRO_MAX_GRP_COL " = :max "
                   "WHERE " PRO_ID_COL " = :id");
    update.bindValue(":name", project.getName());
    update.bindValue(":min", project.getMinGroupSize());
    update.bindValue(":max", project.getMaxGroupSize());
    update.bindValue(":id", project.getId());
    result = update.exec();

    db.close();
    return result;
}

QMap<int, Student*>* ProjectStorage::getStudents(const Project& project)
{
    QMap<int, Student*>* students = new QMap<int, Student*>();

    db.open();

    QSqlQuery select(db);
    select.prepare("SELECT * FROM " STU_TABLE " NATURAL JOIN (SELECT " ENRL_STU_COL " AS " STU_ID_COL
                   " FROM " ENRL_TABLE " WHERE = :pid");
    select.bindValue(":pid", project.getId());
    select.exec();

    while(select.next()) {
        int id = select.value(STU_ID_COL).toInt();
        QString* name = new QString(select.value(PRO_NAME_COL).toString());
        students->insert(id, new ProxyStudent(id, name, new StudentStorage(db)));
    }

    db.close();
    return students;
}

QMap<int, Group*>* ProjectStorage::getGroups(const Project& project)
{
    QMap<int, Group*>* groups = new QMap<int, Group*>();

    db.open();

    QSqlQuery select(db);
    select.prepare("SELECT * FROM " STU_TABLE " NATURAL JOIN (SELECT " ENRL_STU_COL " AS " STU_ID_COL ", "
                   ENRL_GRP_COL " FROM " ENRL_TABLE " WHERE " ENRL_PRO_COL "= :pid)");
    select.bindValue(":pid", project.getId());
    select.exec();
    while(select.next())
    {
        int grpId = select.value(ENRL_GRP_COL).toInt();
        if (!(groups->contains(grpId)))
                groups->insert(grpId, new Group(grpId, new QMap<int, Student*>));
        int stuId = select.value(STU_ID_COL).toInt();
        QString* name = new QString(select.value(PRO_NAME_COL).toString());
        (*groups)[grpId]->getStudents().insert(stuId, new ProxyStudent(stuId, name, new StudentStorage(db)));
    }

    db.close();
    return groups;
}

bool ProjectStorage::setGroups(const Project& project, const QList<Group*>& groups)
{
    db.open();

    QSqlQuery update(db);
    update.exec("PRAGMA foreign_keys = ON;");
    update.prepare("UPDATE " ENRL_TABLE " SET " ENRL_GRP_COL " = :gid "
                   "WHERE " ENRL_STU_COL " = :sid AND " ENRL_PRO_COL " = :pid");
    update.bindValue(":pid", project.getId());

    int rows = 0;
    Group* group = NULL;
    QMap<int, Student*> students;

    QList<Group*>::const_iterator git;
    QMap<int, Student*>::const_iterator cit;
    for (git = groups.cbegin(); git != groups.cend(); ++git)
    {
        group = *git;
        update.bindValue(":gid", group->getId());
        students = group->getStudents();
        for (cit = students.cbegin(); cit != students.cend(); ++cit)
        {
            update.bindValue(":sid", (*cit)->getId());
            rows = update.exec();
            if (rows < 1)
            {
                db.close();
                return false;
            }
        }
    }

    db.close();
    return true;
}

bool ProjectStorage::setGroups(const Project& project, const QMap<int, Group*>& groups)
{

}
