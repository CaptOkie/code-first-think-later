#include "proxystudent.h"

ProxyStudent::ProxyStudent(int id, QString* name)
    : Student(id, name), realStudent(NULL)
{ }

ProxyStudent::~ProxyStudent()
{ }
