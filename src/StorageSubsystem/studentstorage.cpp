#include "studentstorage.h"

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
