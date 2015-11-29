#ifndef QUESTIONSTORAGE_H
#define QUESTIONSTORAGE_H

#include <QtSql>
#include <list>

#include "question.h"

class QuestionStorage
{
public:
    QuestionStorage();
    ~QuestionStorage();

    std::list<Answer> getAnswers(Question);
    Answer getPersonalAnswer(Question);
    Answer getDesiredAnswer(Question);
    void setPersonal(Question, Answer);
    void setDesired(Question, Answer);


private:
    QSqlDatabase db;
    //void setupDB();
    //void populateDatabase();
};

#endif // QUESTIONSTORAGE_H
