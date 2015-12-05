#ifndef REALQUESTION_H
#define REALQUESTION_H

#include "question.h"

class RealQuestion : public Question
{
    public:
        RealQuestion(int id, QString* text, QString* category);
        RealQuestion(int id, const QString& text, const QString& category);
        ~RealQuestion();

    public:
        virtual int getId() const;
        virtual const QString& getText() const;
        virtual const QString& getCategory() const;

        virtual const QMap<int, Answer*>& getAnswers() const;
        virtual const Answer& getPersonal() const;
        virtual const Answer& getDesired() const;

        void setAnswers(QMap<int, Answer*>* answers);
        virtual bool setPersonal(const Answer& answer);
        virtual bool setDesired(const Answer& answer);

    private:
        int id;
        QString* text;
        QString* category;
        QMap<int, Answer*>* answers;
        Answer* personal;
        Answer* desired;

    private:
        void deleteAnswers(QMap<int, Answer*>* answers);
};

#endif // REALQUESTION_H
