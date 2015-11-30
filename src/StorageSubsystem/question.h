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

        virtual const QMap<int, Answer*>& getAnswers() const = 0;
        virtual const Answer& getPersonalAnswer() const = 0;
        virtual const Answer& getDesiredAnswer() const = 0;

        virtual void setPersonal(const Answer& answer) = 0;
        virtual void setDesired(const Answer& answer) = 0;
};

#endif // QUESTION_H
