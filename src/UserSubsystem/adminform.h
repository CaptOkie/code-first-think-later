#ifndef ADMINFORM_H
#define ADMINFORM_H

#include <QMainWindow>
#include "logoutdialog.h"
#include "StorageSubsystem/project.h"
#include <QTreeWidget>

namespace Ui {
class AdminForm;
}

class AdminControl;

class AdminForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminForm(AdminControl&, QWidget *parent = 0);
    ~AdminForm();

    void editProject();
    void setName(QString);
    void logout();
    void show(QMap<QString, Project*>&);
    void update(QMap<QString, Project*>& projects);

private:
    Ui::AdminForm *ui;
    LogoutDialog logoutDialog;
    AdminControl& ctrl;

    void displayStuNames();
    void newProject();
    void resizeTable(QTreeWidget*);
    void addTreeItem(QTreeWidget*, QStringList);

private slots:
    void logoutDialogFinished();
};

#endif // ADMINFORM_H
