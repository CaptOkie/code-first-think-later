#ifndef STUDENTSTORAGE_H
#define STUDENTSTORAGE_H

#include <QtSql>
#include <QList>

class StudentStorage
{
public:
    StudentStorage();
    ~StudentStorage();

private:
    QSqlDatabase db;
    //void setupDB();
    //void populateDatabase();
};

#endif // STUDENTSTORAGE_H
