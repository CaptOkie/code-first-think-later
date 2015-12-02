#ifndef ADMINFORM_H
#define ADMINFORM_H

#include <QMainWindow>
#include "ProjectSubsystem/projectform.h"
#include "logoutdialog.h"
#include <QTreeWidget>

namespace Ui {
class AdminForm;
}

class AdminControl;

class AdminForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminForm(AdminControl& ctrl, QWidget *parent = 0);
    ~AdminForm();

    void editProject();
    void setName(QString);
    void logout();
    QTreeWidget* getTreeWidget();
    void addTreeItem(QStringList);

private:
    Ui::AdminForm *ui;
    ProjectForm projectForm;
    LogoutDialog logoutDialog;
    AdminControl& ctrl;

private slots:
    void logoutDialogFinished();
};

#endif // ADMINFORM_H
