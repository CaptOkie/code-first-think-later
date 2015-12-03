#ifndef STUDENTCONTROL_H
#define STUDENTCONTROL_H

#include <QString>
#include <QDesktopWidget>
#include <QApplication>
#include <QStyle>

#include "usercontrol.h"
#include "studentform.h"
#include "StorageSubsystem/student.h"
#include "ProfileSubsystem/profilecontrol.h"

class StudentControl : public UserControl
{
public:
    StudentControl(Student* student);
    ~StudentControl();

    void start();
    void editProfile();

private:
    StudentForm stuForm;
    Student* student;
    ProfileControl editProfileControl;
};

#endif // STUDENTCONTROL_H
