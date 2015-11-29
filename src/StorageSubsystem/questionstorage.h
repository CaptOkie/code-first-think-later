#ifndef QUESTIONSTORAGE_H
#define QUESTIONSTORAGE_H

#include <QtSql>
#include <QMap>

#include "question.h"
#include "answer.h"

class QuestionStorage
{
    public:
        QuestionStorage();
        ~QuestionStorage();

        QMap<int, Answer>* getAnswers(const Question& question);
        Answer* getPersonalAnswer(const Question& question);
        Answer* getDesiredAnswer(const Question& question);

        void setPersonal(const Question& question, const Answer& answer);
        void setDesired(const Question& question, const Answer& answer);


    private:
        QSqlDatabase& db;
};

#endif // QUESTIONSTORAGE_H
