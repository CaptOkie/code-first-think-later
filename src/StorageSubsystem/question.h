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

        virtual bool setResponse(int personal, int desired) = 0;
        virtual bool setResponse(const Answer& personal, const Answer& desired) = 0;
};

#endif // QUESTION_H
