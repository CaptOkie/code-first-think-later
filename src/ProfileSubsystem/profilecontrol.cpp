#include "profilecontrol.h"

ProfileControl::ProfileControl(Student& student)
    : profileForm(*this, student), student(student)
{ }

ProfileControl::~ProfileControl()
{ }

void ProfileControl::start()
{
    profileForm.show(student.getQuestions());
}
