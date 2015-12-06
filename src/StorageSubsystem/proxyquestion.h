#ifndef PROXYQUESTION_H
#define PROXYQUESTION_H

#include "question.h"
#include "realquestion.h"
#include "questionstorage.h"
#include "indicator.h"

class ProxyQuestion : public Question
{
    public:
        ProxyQuestion(int id, QString* text, QString* category, QuestionStorage* storage);
        ~ProxyQuestion();

    public:
        virtual int getId() const;
        virtual const QString& getText() const;
        virtual const QString& getCategory() const;

        virtual const QMap<int, Answer*>& getAnswers() const;
        virtual const Answer& getPersonal() const;
        virtual const Answer& getDesired() const;

        virtual bool setResponse(int personal, int desired);
        virtual bool setResponse(const Answer& personal, const Answer& desired);

    private:
        Indicator* hasAnswers;
        Indicator* hasResponse;
        RealQuestion* realQuestion;
        QuestionStorage* storage;

    private:
        void loadAnswers() const;
};

#endif // PROXYQUESTION_H
