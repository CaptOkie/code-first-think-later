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
#include "ProjectSubsystem/projectcontrol.h"

class AdminControl : public UserControl
{
public:
    AdminControl(Admin* admin);
    ~AdminControl();

    const QMap<int, Student*>& getStuNames(QString&);
    void start();
    void newProjectStart();
    void editProjectStart(QString);
    void editProject(Project*);
    void addNewProject(RealProject);

private:
    AdminForm adminForm;
    Admin* admin;
    ProjectControl projectControl;

    void loadProjects();

};

#endif // ADMINCONTROL_H
