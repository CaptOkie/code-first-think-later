#include "studentstorage.h"

StudentStorage::StudentStorage(QSqlDatabase& db)
    : db(db)
{ }

StudentStorage::~StudentStorage()
{ }

QMap<int, Question>* StudentStorage::getQuestions(const Student& student)
{
    QMap<int, Question> questions = new QMap<int, Question>;

    return questions;
}
