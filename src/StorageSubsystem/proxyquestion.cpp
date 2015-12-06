#include "proxyquestion.h"

ProxyQuestion::ProxyQuestion(int id, QString* text, QString* category, QuestionStorage* storage)
    : hasAnswers(new Indicator(false)), hasPersonal(new Indicator(false)), hasDesired(new Indicator(false)),
      realQuestion(new RealQuestion(id, text, category)), storage(storage)
{ }

ProxyQuestion::~ProxyQuestion()
{
    if (hasAnswers)
        delete hasAnswers;
    if (realQuestion)
        delete realQuestion;
    if (storage)
        delete storage;
}

int ProxyQuestion::getId() const
{
    return realQuestion->getId();
}

const QString& ProxyQuestion::getText() const
{
    return realQuestion->getText();
}

const QString& ProxyQuestion::getCategory() const
{
    return realQuestion->getCategory();
}

const QMap<int, Answer*>& ProxyQuestion::getAnswers() const
{
    if (!hasAnswers->getValue())
    {
        hasAnswers->toggleValue();
        QMap<int, Answer*>* answers = storage->getAnswers(*realQuestion);
        realQuestion->setAnswers(answers);
    }

    return realQuestion->getAnswers();
}

const Answer& ProxyQuestion::getPersonal() const
{
    if (!hasPersonal->getValue())
    {
//        hasPersonal->
    }
    return realQuestion->getPersonal();
}

const Answer& ProxyQuestion::getDesired() const
{
    return realQuestion->getDesired();
}

bool ProxyQuestion::setPersonal(const Answer& answer)
{
    return realQuestion->setPersonal(answer);
}

bool ProxyQuestion::setDesired(const Answer& answer)
{
    return realQuestion->setDesired(answer);
}
