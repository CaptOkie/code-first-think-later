#ifndef ADMINCONTROL_H
#define ADMINCONTROL_H

#include <QString>
#include <QDesktopWidget>
#include <QApplication>
#include <QStyle>

#include "usercontrol.h"
#include "adminform.h"

class AdminControl : public UserControl
{
public:
    AdminControl();
    ~AdminControl();

    void start();
    AdminForm* adminForm;

};

#endif // ADMINCONTROL_H
