#include "realquestion.h"

RealQuestion::RealQuestion(int id, QString* text, QString* category)
    : id(id), text(text), category(category), answers(new QMap<int, Answer*>()), desired(NULL), personal(NULL)
{ }

RealQuestion::~RealQuestion()
{ }

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

void RealQuestion::setPersonal(const Answer& answer)
{
    if (answers->contains(answer.getId()))
    {
        QMap<int, Answer*>::iterator it = answers->find(answer.getId());
        if (it != answers->end())
        {
            personal = it.value();
        }
    }
}

void RealQuestion::setDesired(const Answer& answer)
{
    if (answers->contains(answer.getId()))
    {
        QMap<int, Answer*>::iterator it = answers->find(answer.getId());
        if (it != answers->end())
        {
            desired = it.value();
        }
    }
}
