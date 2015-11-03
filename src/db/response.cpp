#include "response.h"

Response::Response(int question, int personal, int desired)
    : question(question), personal(personal), desired(desired)
{ }

Response::Response(const Response& copy)
    : question(copy.getQuestion()), personal(copy.getPersonal()), desired(copy.getDesired())
{ }

Response::~Response()
{ }

int Response::getQuestion() const
{
    return question;
}

int Response::getPersonal() const
{
    return personal;
}

int Response::getDesired() const
{
    return desired;
}
