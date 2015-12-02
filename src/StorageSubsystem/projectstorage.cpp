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
//    select.prepare("SELECT ")
    db.close();
    return groups;
}

void ProjectStorage::setGroups(const Project& project, const QList<Group*>& groups)
{

}

void ProjectStorage::setGroups(const Project& project, const QMap<int, Group*>& groups)
{

}
