#include "response.h"

Response::Response(int question, int personal, int desired)
    : question(question), personal(personal), desired(desired)
{ }

Response::Response(const Response& response)
    : question(response.getQuestion()), personal(response.getPersonal()), desired(response.getDesired())
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
