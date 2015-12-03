#include "studentform.h"
#include "ui_studentform.h"
#include "studentcontrol.h"

StudentForm::StudentForm(StudentControl& ctrl, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentForm),
    logoutDialog(this),
    ctrl(ctrl)
{
    ui->setupUi(this);

    connect(ui->logoutButton, &QPushButton::released, this, &StudentForm::logout);
    connect(ui->editProfileButton, &QPushButton::released, this, &StudentForm::editProfile);
    connect(&logoutDialog, &QDialog::finished, this, &StudentForm::logoutDialogFinished);
}

StudentForm::~StudentForm()
{
    delete ui;
}

void StudentForm::logout()
{
    logoutDialog.showDialog();
}

void StudentForm::setName(QString name)
{
    ui->nameLabel->setText(name);
}

void StudentForm::logoutDialogFinished()
{
    if (logoutDialog.result() == 1 || logoutDialog.result() == 2)
    {
        close();
    }
}

void StudentForm::editProfile()
{
    ctrl.editProfile();
}
