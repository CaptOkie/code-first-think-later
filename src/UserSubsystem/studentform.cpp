#include "studentform.h"
#include "ui_studentform.h"

StudentForm::StudentForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentForm),
    logoutDialog(this)
{
    ui->setupUi(this);

    connect(ui->logoutButton, &QPushButton::released, this, &StudentForm::logout);
    connect(&logoutDialog, SIGNAL(finished (int)), this, SLOT(logoutDialogFinished(int)));
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

void StudentForm::logoutDialogFinished(int result)
{
    if (result == QDialog::Accepted || result == 0)
    {
        close();
    }
}
