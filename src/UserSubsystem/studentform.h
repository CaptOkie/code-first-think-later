#ifndef STUDENTFORM_H
#define STUDENTFORM_H

#include "logoutdialog.h"
#include "confirmationdialog.h"
#include "StorageSubsystem/project.h"
#include <QTreeWidget>

#include <QMainWindow>

namespace Ui {
class StudentForm;
}

class StudentControl;

class StudentForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentForm(StudentControl&, QWidget *parent = 0);
    ~StudentForm();
    void setName(QString);
    void show(const QMap<QString, Project*>&, const QMap<QString, Project*>&);

private:
    Ui::StudentForm *ui;
    LogoutDialog logoutDialog;
    ConfirmationDialog confirmationDialog;
    StudentControl& ctrl;
    void addTreeItem(QTreeWidget*, QStringList);
    void resizeTable(QTreeWidget*);

private slots:
    void logout();
    void logoutDialogFinished();
    void editProfile();
    void joinProject();
    void leaveProject();
    void leaveProjectDialog();
    void jProjectSelect();
    void lProjectSelect();
    void enableButton(QString, bool);
};

#endif // STUDENTFORM_H
