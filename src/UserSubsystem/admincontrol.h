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
#include "StorageSubsystem/project.h"

class AdminControl : public UserControl
{
public:
    AdminControl(Admin* admin);
    ~AdminControl();

    void start();
    void editProject();
    QMap<int, Student*> getStuNames(QString);

private:
    AdminForm adminForm;
    Admin* admin;

    void loadProjects();

};

#endif // ADMINCONTROL_H
