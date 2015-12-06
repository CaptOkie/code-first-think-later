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

QMap<int, Group*>* ProjectStorage::setGroups(const Project& project, const QList<Group*>& groups)
{
    QMap<int, Group*>* groupsMap = new QMap<int, Group*>();
    int id = 1;

    for (QList<Group*>::const_iterator it = groups.cbegin(); it != groups.cend(); ++it)
    {
        Group* group = *it;
        group->setId(id);
        groupsMap->insert(group->getId(), group);
        ++id;
    }

    if (setGroups(project, *groupsMap))
        return groupsMap;

    delete groupsMap;
    return NULL;
}

bool ProjectStorage::setGroups(const Project& project, const QMap<int, Group*>& groups)
{
    db.open();
    db.transaction();

    QSqlQuery update(db);
    update.exec("PRAGMA foreign_keys = ON;");
    update.prepare("UPDATE " ENRL_TABLE " SET " ENRL_GRP_COL " = :gid "
                   "WHERE " ENRL_STU_COL " = :sid AND " ENRL_PRO_COL " = :pid");
    update.bindValue(":pid", project.getId());

    int rows = 0;
    QMap<int, Student*> students;
    Group* group = NULL;
    bool isValid = true;

    for (QMap<int, Group*>::const_iterator git = groups.cbegin(); git != groups.cend() && isValid; ++git)
    {
        group = git.value();
        update.bindValue(":gid", group->getId());
        students = group->getStudents();
        for (QMap<int, Student*>::const_iterator cit = students.cbegin(); cit != students.cend() && isValid; ++cit)
        {
            update.bindValue(":sid", (*cit)->getId());
            rows = update.exec();
            isValid = (rows > 0) && !(update.lastError().isValid());
        }
    }

    if (isValid)
        db.commit();
    else
        db.rollback();
    db.close();
    return isValid;
}
