#ifndef PROFILECONTROL_H
#define PROFILECONTROL_H

#include <QStyle>
#include <QApplication>
#include <QDesktopWidget>

#include "profileform.h"
#include "StorageSubsystem/student.h"

class ProfileControl
{
public:
    ProfileControl(Student*);
    ~ProfileControl();
    void start();

private:
    ProfileForm profileForm;
    Student* student;
};

#endif // PROFILECONTROL_H
