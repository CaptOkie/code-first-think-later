#include "proxystudent.h"

ProxyStudent::ProxyStudent(int id, QString* name, StudentStorage* storage)
    : Student(id, name), realStudent(NULL), storage(storage)
{ }

ProxyStudent::~ProxyStudent()
{
    if(realStudent)
        delete realStudent;

    if(storage)
        delete storage;
}
