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
    deleteAnswers(this->answers);
    personal = new Answer();
    desired = new Answer();
    this->answers = answers;
}

bool RealQuestion::setResponse(int personal, int desired)
{
    QMap<int, Answer*>::iterator pit = answers->find(personal);
    QMap<int, Answer*>::iterator dit = answers->find(desired);
    if ((pit != answers->end()) && (dit != answers->end()))
    {
        cleanResponse(this->personal);
        this->personal = pit.value();

        cleanResponse(this->desired);
        this->desired = dit.value();
        return true;
    }

    return false;
}

bool RealQuestion::setResponse(const Answer& personal, const Answer& desired)
{
    return setResponse(personal.getId(), desired.getId());
}

void RealQuestion::cleanResponse(Answer* answer)
{
    if (answer && !(answers->contains(answer->getId())))
        delete answer;
}

void RealQuestion::deleteResponse(Answer* answer)
{
    if (answer)
    {
        Answer* p = answers->take(answer->getId());
        if (p && (p != answer))
            delete p;
        delete answer;
    }
}

void RealQuestion::deleteAnswers(QMap<int, Answer*>* answers)
{
    if (answers)
    {
        deleteResponse(personal);
        deleteResponse(desired);
        for (QMap<int, Answer*>::iterator it = answers->begin(); it != answers->end(); ++it)
        {
            Answer* answer = it.value();
            delete answer;
        }

        delete answers;
    }
}
