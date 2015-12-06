#include "confirmationdialog.h"
#include "ui_confirmationdialog.h"

ConfirmationDialog::ConfirmationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfirmationDialog)
{
    ui->setupUi(this);

    connect(ui->confirmButton, &QPushButton::released, this, &ConfirmationDialog::confirm);
    connect(ui->cancelButton, &QPushButton::released, this, &ConfirmationDialog::cancel);
}

ConfirmationDialog::~ConfirmationDialog()
{
    delete ui;
}

void ConfirmationDialog::confirm()
{
    QDialog::accept();
}

void ConfirmationDialog::cancel()
{
    QDialog::reject();
}

void ConfirmationDialog::showDialog(QString type)
{
    if (type == "stu")
    {
        ui->descriptionLabel->setText("Are you sure that you want to leave this project?");
        ui->actionLabel->setText("leave");
    }
    else if (type == "admin")
    {
        ui->descriptionLabel->setText("Are you sure that you want to delete this project?");
        ui->actionLabel->setText("delete");
    }
    exec();
}
