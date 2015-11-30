#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include <QMap>

#include "answer.h"

class Question
{
    public:
        Question();
        virtual ~Question();

    protected:
        int id;
        QString* personal;
        QString* desired;
        QString* category;

    public:
        int getId() const;
        const QString& getPersonal() const;
        const QString& getDesired() const;
        const QString& getCategory() const;

        virtual const QMap<int, Answer>& getAnswers() const;
        virtual const QMap<int, Answer>& getPersonalAnswer() const;
        virtual const Answer& getDesiredAnswer() const;

        virtual void setPersonal(const Answer& answer);
        virtual void setDesired(const Answer& answer);
};

#endif // QUESTION_H
