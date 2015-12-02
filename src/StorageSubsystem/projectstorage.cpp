#include "projectstorage.h"
#include "storage.h"

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

QMap<int, Student*>* getStudents(const Project& project)
{/*
    QMap<int, Student*>* students = new QMap<int, Student*>*();

    db.open();

    QSqlQuery select(db);
    select.prepare("SELECT * FROM " PRO_TABLE);
    select.exec();

    while(select.next()) {
        QString name = QString(select.value(PRO_NAME_COL).toString());
        int min = select.value(PRO_MIN_GRP_COL).toInt();
        int max = select.value(PRO_MAX_GRP_COL).toInt();
        (*projects)(Project(new QString(name), new GroupSize(min, max)));
    }

    db.close();
*/}

QMap<int, Group*>* ProjectStorage::getGroups(const Project& project)
{

}

void ProjectStorage::setGroups(const Project& project, const QList<Group*>& groups)
{

}

void ProjectStorage::setGroups(const Project& project, const QMap<int, Group*>& groups)
{

}
