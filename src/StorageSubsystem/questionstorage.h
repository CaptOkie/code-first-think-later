#ifndef QUESTIONSTORAGE_H
#define QUESTIONSTORAGE_H

#include <QtSql>
#include <QMap>

#include "question.h"
#include "answer.h"
#include "student.h"

class QuestionStorage
{
    public:
        QuestionStorage(QSqlDatabase& db, const Student& student);
        ~QuestionStorage();

        QMap<int, Answer*>* getAnswers(const Question& question);
        int getPersonalAnswer(const Question& question);
        int getDesiredAnswer(const Question& question);

        void setPersonal(const Question& question, const Answer& answer);
        void setDesired(const Question& question, const Answer& answer);


    private:
        QSqlDatabase& db;
        const Student& student;
};

#endif // QUESTIONSTORAGE_H
