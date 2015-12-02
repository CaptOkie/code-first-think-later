#ifndef ADMINFORM_H
#define ADMINFORM_H

#include <QMainWindow>
#include "ProjectSubsystem/projectform.h"
#include "logoutdialog.h"

namespace Ui {
class AdminForm;
}

class AdminForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminForm(QWidget *parent = 0);
    ~AdminForm();

    void editProject();
    void setName(QString);
    void logout();

private:
    Ui::AdminForm *ui;
    ProjectForm projectForm;
    LogoutDialog logoutDialog;
};

#endif // ADMINFORM_H
