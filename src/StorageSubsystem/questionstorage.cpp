#include "questionstorage.h"
#include "storage.h"

QuestionStorage::QuestionStorage(QSqlDatabase& db, const Student& student)
    : db(db), student(student)
{ }

QuestionStorage::~QuestionStorage()
{
    if(db.isOpen()) {
        db.close();
    }
}

QMap<int, Answer*>* QuestionStorage::getAnswers(const Question& question)
{
    QMap<int, Answer*>* answers = new QMap<int, Answer*>();

    db.open();

    QSqlQuery select(db);
    select.prepare("SELECT * FROM " ANSR_TABLE " WHERE " ANSR_QID_COL " = :qid");
    select.bindValue(":qid", question.getId());
    select.exec();
    while (select.next())
    {
        int id = select.value(ANSR_ID_COL).toInt();
        QString text = select.value(ANSR_VAL_COL).toString();
        answers->insert(id, new Answer(id, new QString(text)));
    }

    db.close();
    return answers;
}

int QuestionStorage::getPersonalAnswer(const Question& question)
{
    int id = -1;

    db.open();

    QSqlQuery select(db);
    select.prepare("SELECT " ANSR_ID_COL " FROM " ANSR_TABLE " NATURAL JOIN (SELECT " RESP_PSNL_ANSR_COL " AS " ANSR_ID_COL " FROM "
                   RESP_TABLE " WHERE " RESP_STU_COL " = :sid AND " RESP_QSTN_COL " = :qid)");
    select.bindValue(":qid", question.getId());
    select.bindValue(":sid", student.getId());
    select.exec();

    if (select.next())
    {
        id = select.value(ANSR_ID_COL).toInt();
    }

    db.close();
    return id;
}

int QuestionStorage::getDesiredAnswer(const Question& question)
{
    int id = -1;

    db.open();

    QSqlQuery select(db);
    select.prepare("SELECT " ANSR_ID_COL " FROM " ANSR_TABLE " NATURAL JOIN (SELECT " RESP_DESR_ANSR_COL " AS " ANSR_ID_COL " FROM "
                   RESP_TABLE " WHERE " RESP_STU_COL " = :sid AND " RESP_QSTN_COL " = :qid)");
    select.bindValue(":qid", question.getId());
    select.bindValue(":sid", student.getId());
    select.exec();
    if (select.next())
    {
        id = select.value(ANSR_ID_COL).toInt();
    }

    db.close();
    return id;
}

bool QuestionStorage::setResponse(const Question& question, int personal, int desired)
{
    db.open();

    QSqlQuery update(db);
    update.exec("PRAGMA foreign_keys = ON;");
    update.prepare("UPDATE " RESP_TABLE " SET " RESP_PSNL_ANSR_COL " = :personal, " RESP_DESR_ANSR_COL " = :desired "
                   "WHERE " RESP_STU_COL " = :sid AND " RESP_QSTN_COL " = :qid");
    update.bindValue(":personal", personal);
    update.bindValue(":desired", desired);
    update.bindValue(":sid", student.getId());
    update.bindValue(":qid", question.getId());
    update.exec();

    int rows = update.numRowsAffected();
    db.close();
    return (rows > 0);
}

bool QuestionStorage::setResponse(const Question &question, const Answer &personal, const Answer &desired)
{
    return setResponse(question, personal.getId(), desired.getId());
}
