#ifndef STUDENTCONTROL_H
#define STUDENTCONTROL_H

#include <QString>
#include <QDesktopWidget>
#include <QApplication>
#include <QStyle>

#include "usercontrol.h"
#include "studentform.h"
#include "StorageSubsystem/student.h"

class StudentControl : public UserControl
{
public:
    StudentControl(Student* student);
    ~StudentControl();

    void start();

private:
    StudentForm stuForm;
    Student* student;
};

#endif // STUDENTCONTROL_H
