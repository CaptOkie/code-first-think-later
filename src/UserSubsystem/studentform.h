#ifndef STUDENTFORM_H
#define STUDENTFORM_H

#include "logoutdialog.h"

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

private:
    Ui::StudentForm *ui;
    LogoutDialog logoutDialog;
    StudentControl& ctrl;

private slots:
    void logout();
    void logoutDialogFinished();
    void editProfile();
};

#endif // STUDENTFORM_H
