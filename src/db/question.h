#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include <QList>

#include "answer.h"

class Question
{
    public:
        Question(int, QString*, QString*, QString*, QList<Answer>*);
        Question(int, const QString&, const QString&, const QString&, QList<Answer>*);
        Question(const Question&);
        ~Question();

        int getId() const;
        const QString& getPersonal() const;
        const QString& getDesired() const;
        const QString& getCategory() const;
        const QList<Answer>& getAnswers() const;

    private:
        int id;
        QString* personal;
        QString* desired;
        QString* category;
        QList<Answer>* answers;
};

#endif // QUESTION_H
