#include "adminstorage.h"
#include "proxyproject.h"
#include "projectstorage.h"

AdminStorage::AdminStorage(QSqlDatabase& db)
    : db(db)
{ }

AdminStorage::~AdminStorage()
{ }

QMap<QString, Project*>* AdminStorage::getProjects()
{
    QMap<QString, Project*>* projects = new QMap<QString, Project*>();
    db.open();

    QSqlQuery select(db);
    select.prepare("SELECT * FROM " PRO_TABLE);
    select.exec();

    while(select.next()) {
        int id = select.value(PRO_ID_COL).toInt();
        QString name = QString(select.value(PRO_NAME_COL).toString());
        int min = select.value(PRO_MIN_GRP_COL).toInt();
        int max = select.value(PRO_MAX_GRP_COL).toInt();
        projects->insert(name, (Project*)new ProxyProject(id, new QString(name), min, max, new ProjectStorage(db)));
    }

    db.close();
    return projects;
}

void AdminStorage::deleteProject(const Project &project)
{
    db.open();
    db.exec("PRAGMA foreign_keys = ON;");

    QSqlQuery remove(db);
    remove.prepare("DELETE FROM " PRO_TABLE " WHERE " PRO_NAME_COL " = :name");
    remove.bindValue(":name", project.getName());
    remove.exec();

    db.close();
}

void AdminStorage::addProject(const Project &project)
{
    db.open();

    QSqlQuery insert(db);
    insert.prepare("INSERT INTO " PRO_TABLE " (" PRO_NAME_COL " , " PRO_MIN_GRP_COL " , " PRO_MAX_GRP_COL ")"
                   "VALUES (:name, :min, :max)");
    insert.bindValue(":name", project.getName());
    insert.bindValue(":min", project.getMinGroupSize());
    insert.bindValue(":max", project.getMaxGroupSize());
    insert.exec();

    db.close();
}
