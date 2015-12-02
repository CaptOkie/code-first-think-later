#ifndef ADMINCONTROL_H
#define ADMINCONTROL_H

#include <QString>
#include <QDesktopWidget>
#include <QApplication>
#include <QStyle>

#include "usercontrol.h"
#include "adminform.h"
#include "StorageSubsystem/admin.h"

class AdminControl : public UserControl
{
public:
    AdminControl(Admin* admin);
    ~AdminControl();

    void start();

private:
    AdminForm adminForm;
    Admin* admin;

};

#endif // ADMINCONTROL_H
