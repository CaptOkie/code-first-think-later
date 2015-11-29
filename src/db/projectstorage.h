#ifndef PROJECTSTORAGE_H
#define PROJECTSTORAGE_H

#include <QtSql>
#include <QList>

class ProjectStorage
{
public:
    ProjectStorage();
    ~ProjectStorage();

private:
    QSqlDatabase db;
    //void setupDB();
    //void populateDatabase();
};

#endif // PROJECTSTORAGE_H
