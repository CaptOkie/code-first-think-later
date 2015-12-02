#ifndef STUDENTCONTROL_H
#define STUDENTCONTROL_H

#include <QString>
#include <QDesktopWidget>
#include <QApplication>
#include <QStyle>

#include "usercontrol.h"
#include "studentform.h"

class StudentControl : public UserControl
{
public:
    StudentControl();
    ~StudentControl();

    void start();
    StudentForm* stuForm;
};

#endif // STUDENTCONTROL_H
