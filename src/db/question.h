#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include <QList>

#include "answer.h"
#include "response.h"

class Question
{
    public:
        Question(int id, QString* personal, QString* desired, QString* category, QList<Answer>* answers, QList<Response>* responses);
        Question(int id, const QString& personal, const QString& desired, const QString& category, QList<Answer>* answers, QList<Response>* responses);
        Question(const Question& copy);
        ~Question();

        int getId() const;
        const QString& getPersonal() const;
        const QString& getDesired() const;
        const QString& getCategory() const;
        const QList<Answer>& getAnswers() const;
        const QList<Response>& getResponses() const;

    private:
        int id;
        QString* personal;
        QString* desired;
        QString* category;
        QList<Answer>* answers;
        QList<Response>* responses;
};

#endif // QUESTION_H
