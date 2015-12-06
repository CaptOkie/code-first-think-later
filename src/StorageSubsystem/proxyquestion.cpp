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
        loadAnswers();

    return realQuestion->getAnswers();
}

const Answer& ProxyQuestion::getPersonal() const
{
    if (!hasAnswers->getValue())
        loadAnswers();

    if (!hasPersonal->getValue())
    {
        hasPersonal->toggleValue();
        int aid = storage->getPersonalAnswer(*realQuestion);
        realQuestion->setPersonal(aid);
    }
    return realQuestion->getPersonal();
}

const Answer& ProxyQuestion::getDesired() const
{
    if (!hasAnswers->getValue())
        loadAnswers();

    if (!hasDesired->getValue())
    {
        hasDesired->toggleValue();
        int aid = storage->getDesiredAnswer(*realQuestion);
        realQuestion->setDesired(aid);
    }
    return realQuestion->getDesired();
}

bool ProxyQuestion::setPersonal(int answer)
{
    return realQuestion->setPersonal(answer);
}

bool ProxyQuestion::setDesired(int answer)
{
    return realQuestion->setPersonal(answer);
}

bool ProxyQuestion::setPersonal(const Answer& answer)
{
    return realQuestion->setPersonal(answer);
}

bool ProxyQuestion::setDesired(const Answer& answer)
{
    return realQuestion->setDesired(answer);
}

void ProxyQuestion::loadAnswers() const
{
    hasAnswers->toggleValue();
    QMap<int, Answer*>* answers = storage->getAnswers(*realQuestion);
    realQuestion->setAnswers(answers);
}
