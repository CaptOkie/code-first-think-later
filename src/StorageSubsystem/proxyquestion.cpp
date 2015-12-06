#include "proxyquestion.h"

ProxyQuestion::ProxyQuestion(int id, QString* text, QString* category, QuestionStorage* storage)
    : hasAnswers(new Indicator(false)), hasResponse(new Indicator(false)),
      realQuestion(new RealQuestion(id, text, category)), storage(storage)
{ }

ProxyQuestion::~ProxyQuestion()
{
    if (hasAnswers)
        delete hasAnswers;
    if (hasResponse)
        delete hasResponse;
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

    if (!hasResponse->getValue())
    {
        hasResponse->toggleValue();
        int pid = storage->getPersonalAnswer(*realQuestion);
        int did = storage->getDesiredAnswer(*realQuestion);
        if (pid > -1 && did > -1)
        {
            hasResponse->toggleValue();
            realQuestion->setResponse(pid, did);
        }
    }
    return realQuestion->getPersonal();
}

const Answer& ProxyQuestion::getDesired() const
{
    if (!hasResponse->getValue())
    {
        hasResponse->toggleValue();
        int pid = storage->getPersonalAnswer(*realQuestion);
        int did = storage->getDesiredAnswer(*realQuestion);
        if (pid > -1 && did > -1)
        {
            hasResponse->toggleValue();
            realQuestion->setResponse(pid, did);
        }
    }
    return realQuestion->getDesired();
}

bool ProxyQuestion::setResponse(int personal, int desired)
{
    if (storage->setResponse(*realQuestion, personal, desired))
        return realQuestion->setResponse(personal, desired);
    return false;
}

bool ProxyQuestion::setResponse(const Answer& personal, const Answer& desired)
{
    if (storage->setResponse(*realQuestion, personal, desired))
        return realQuestion->setResponse(personal, desired);
    return false;
}

void ProxyQuestion::loadAnswers() const
{
    hasAnswers->toggleValue();
    QMap<int, Answer*>* answers = storage->getAnswers(*realQuestion);
    realQuestion->setAnswers(answers);
}
