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

        bool setResponse(const Question& question, int personal, int desired);
        bool setResponse(const Question& question, const Answer& personal, const Answer& desired);

    private:
        QSqlDatabase& db;
        const Student& student;
};

#endif // QUESTIONSTORAGE_H
