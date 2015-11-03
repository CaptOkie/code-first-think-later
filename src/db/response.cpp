#include "response.h"

Response::Response(int personal, int desired, Question* question)
    : personal(personal), desired(desired), question(question)
{ }

Response::Response(int personal, int desired, const Question& question)
    : personal(personal), desired(desired), question(new Question(question))
{ }

Response::Response(const Response& copy)
    : personal(copy.getPersonal()), desired(copy.getDesired()), question(new Question(copy.getQuestion()))
{ }

Response::~Response()
{ }

const Question& Response::getQuestion() const
{
    return *question;
}

int Response::getPersonal() const
{
    return personal;
}

int Response::getDesired() const
{
    return desired;
}
