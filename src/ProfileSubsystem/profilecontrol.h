#ifndef PROFILECONTROL_H
#define PROFILECONTROL_H

#include "profileform.h"
#include "StorageSubsystem/student.h"
#include "response.h"

class ProfileControl
{
public:
    ProfileControl(Student& student);
    ~ProfileControl();

    void start();
    void save(const QList<Response>& responses);

private:
    ProfileForm profileForm;
    Student& student;
};

#endif // PROFILECONTROL_H
