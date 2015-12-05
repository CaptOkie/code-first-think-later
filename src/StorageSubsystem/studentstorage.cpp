#include "studentstorage.h"
#include "proxyproject.h"
#include "storage.h"

StudentStorage::StudentStorage(QSqlDatabase& db)
    : db(db)
{ }

StudentStorage::StudentStorage(StudentStorage &other)
    : db(other.db)
{ }

StudentStorage::~StudentStorage()
{
    if (db.isOpen())
        db.close();
}

QMap<int, Question*>* StudentStorage::getQuestions(const Student& student)
{
    QMap<int, Question*>* questions = new QMap<int, Question*>;

    return questions;
}

QMap<QString, Project*>* StudentStorage::getEnrolledProjects(const Student& student)
{
    QMap<QString, Project*>* projects = new QMap<QString, Project*>();

    db.open();

    QSqlQuery select(db);
    select.prepare("SELECT * FROM " PRO_TABLE " NATURAL JOIN (SELECT " ENRL_PRO_COL " AS " PRO_ID_COL
                   " FROM " ENRL_TABLE " WHERE " ENRL_STU_COL " = :sid)");
    select.bindValue(":sid", student.getId());
    select.exec();
    while(select.next())
    {
        int id = select.value(PRO_ID_COL).toInt();
        QString* name = new QString(select.value(PRO_NAME_COL).toString());
        int minGroupSize = select.value(PRO_MIN_GRP_COL).toInt();
        int maxGroupSize = select.value(PRO_MAX_GRP_COL).toInt();
        projects->insert(*name, new ProxyProject(id, name, minGroupSize, maxGroupSize, new ProjectStorage(db)));
    }

    db.close();
    return projects;
}

QMap<QString, Project*>* StudentStorage::getAvailableProjects(const Student& student)
{
    QMap<QString, Project*>* projects = new QMap<QString, Project*>();

    db.open();

    QSqlQuery select(db);
    select.prepare("SELECT * FROM " PRO_TABLE " EXCEPT "
                   "SELECT * FROM " PRO_TABLE " NATURAL JOIN (SELECT " ENRL_PRO_COL " AS " PRO_ID_COL
                   " FROM " ENRL_TABLE " WHERE " ENRL_STU_COL " = :sid)");
    select.bindValue(":sid", student.getId());
    select.exec();
    while(select.next())
    {
        int id = select.value(PRO_ID_COL).toInt();
        QString* name = new QString(select.value(PRO_NAME_COL).toString());
        int minGroupSize = select.value(PRO_MIN_GRP_COL).toInt();
        int maxGroupSize = select.value(PRO_MAX_GRP_COL).toInt();
        qDebug() << ("Project name: %s\n", *name);
//        projects->insert(*name, new ProxyProject(id, name, minGroupSize, maxGroupSize, new ProjectStorage(db)));
    }

    db.close();
    return projects;
}
