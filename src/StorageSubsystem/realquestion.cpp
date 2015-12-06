#include "realquestion.h"

RealQuestion::RealQuestion(int id, QString* text, QString* category)
    : id(id), text(text), category(category), answers(new QMap<int, Answer*>()),
      personal(new Answer()), desired(new Answer())
{ }

RealQuestion::RealQuestion(int id, const QString& text, const QString& category)
    : id(id), text(new QString(text)), category(new QString(category)), answers(new QMap<int, Answer*>()),
      personal(new Answer()), desired(new Answer())
{ }

RealQuestion::~RealQuestion()
{
    if (text)
        delete text;
    if (category)
        delete category;
    deleteAnswers(answers);
    if (personal)
        delete personal;
    if (desired)
        delete desired;
}

int RealQuestion::getId() const
{
    return id;
}

const QString& RealQuestion::getText() const
{
    return *text;
}

const QString& RealQuestion::getCategory() const
{
    return *category;
}

const QMap<int, Answer*>& RealQuestion::getAnswers() const
{
    return *answers;
}

const Answer& RealQuestion::getPersonal() const
{
    return *desired;
}

const Answer& RealQuestion::getDesired() const
{
    return *personal;
}

void RealQuestion::setAnswers(QMap<int, Answer*>* answers)
{
    this->answers = answers;
}

bool RealQuestion::setPersonal(int answer)
{
    QMap<int, Answer*>::iterator it = answers->find(answer);
    if (it != answers->end())
    {
        personal = it.value();
        return true;
    }

    return false;
}

bool RealQuestion::setDesired(int answer)
{
    QMap<int, Answer*>::iterator it = answers->find(answer);
    if (it != answers->end())
    {
        desired = it.value();
        return true;
    }

    return false;
}

bool RealQuestion::setPersonal(const Answer& answer)
{
    setPersonal(answer.getId());
}

bool RealQuestion::setDesired(const Answer& answer)
{
    setDesired(answer.getId());
}

void RealQuestion::deleteAnswers(QMap<int, Answer*>* answers)
{
    if (answers)
    {
        for (QMap<int, Answer*>::iterator it = answers->begin(); it != answers->end(); ++it)
        {
            Answer* answer = it.value();
            delete answer;
        }

        delete answers;
    }
}
