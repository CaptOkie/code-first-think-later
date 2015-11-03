#include "response.h"

Response::Response(int student, int personal, int desired)
    : student(student), personal(personal), desired(desired)
{ }

Response::Response(const Response& copy)
    : student(copy.getStudent()), personal(copy.getPersonal()), desired(copy.getDesired())
{ }

Response::~Response()
{ }

int Response::getStudent() const
{
    return student;
}

int Response::getPersonal() const
{
    return personal;
}

int Response::getDesired() const
{
    return desired;
}
