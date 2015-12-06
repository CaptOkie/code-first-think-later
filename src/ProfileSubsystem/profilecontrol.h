#ifndef PROFILECONTROL_H
#define PROFILECONTROL_H

#include "profileform.h"
#include "StorageSubsystem/student.h"

class ProfileControl
{
public:
    ProfileControl(Student& student);
    ~ProfileControl();
    void start();

private:
    ProfileForm profileForm;
    Student& student;
};

#endif // PROFILECONTROL_H
