#ifndef ADMINCONTROL_H
#define ADMINCONTROL_H

#include <QString>
#include <QDesktopWidget>
#include <QApplication>
#include <QStyle>
#include <QTreeWidget>
#include <QMap>

#include "usercontrol.h"
#include "adminform.h"
#include "StorageSubsystem/admin.h"
#include "StorageSubsystem/adminstorage.h"

class AdminControl : public UserControl
{
public:
    AdminControl(Admin* admin);
    ~AdminControl();

    void start();
    void editProject();

private:
    AdminForm adminForm;
    Admin* admin;

    void loadProjects();
    //AdminStorage storage;

};

#endif // ADMINCONTROL_H
