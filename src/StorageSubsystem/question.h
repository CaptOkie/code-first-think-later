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

    public:
        virtual int getId() const = 0;
        virtual const QString& getText() const = 0;
        virtual const QString& getCategory() const = 0;

        virtual const QMap<int, Answer*>& getAnswers() const = 0;
        virtual const Answer& getPersonal() const = 0;
        virtual const Answer& getDesired() const = 0;

        virtual bool setPersonal(int answer) = 0;
        virtual bool setDesired(int answer) = 0;
        virtual bool setPersonal(const Answer& answer) = 0;
        virtual bool setDesired(const Answer& answer) = 0;
};

#endif // QUESTION_H
