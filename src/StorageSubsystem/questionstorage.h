#ifndef QUESTIONSTORAGE_H
#define QUESTIONSTORAGE_H

#include <QtSql>
#include <QList>

class QuestionStorage
{
public:
    QuestionStorage();
    ~QuestionStorage();

private:
    QSqlDatabase db;
    //void setupDB();
    //void populateDatabase();
};

#endif // QUESTIONSTORAGE_H
