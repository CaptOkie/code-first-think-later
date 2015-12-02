#include "studentform.h"
#include "ui_studentform.h"

StudentForm::StudentForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentForm),
    logoutDialog(this)
{
    ui->setupUi(this);

    connect(ui->logoutButton, &QPushButton::released, this, &StudentForm::logout);
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
