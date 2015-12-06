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
    if (select.size() == 1)
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
    if (select.size() == 1)
    {
        id = select.value(ANSR_ID_COL).toInt();
    }

    db.close();
    return id;
}

void QuestionStorage::setPersonal(const Question& question, const Answer& answer)
{

}

void QuestionStorage::setDesired(const Question& question, const Answer& answer)
{

}
