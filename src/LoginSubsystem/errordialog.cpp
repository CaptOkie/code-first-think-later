#include "errordialog.h"
#include "ui_errordialog.h"

ErrorDialog::ErrorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorDialog)
{
    ui->setupUi(this);

    connect(ui->acceptButton, &QPushButton::clicked, this, &ErrorDialog::close);
}

ErrorDialog::~ErrorDialog()
{
    delete ui;
}

void ErrorDialog::close()
{
    QDialog::reject();
}

void ErrorDialog::showDialog(QString type)
{
    if (type == "no_input"){
        ui->errorMessageLabel->setText("You did not enter any input. Please enter your ID before pressing 'Login'.");
    }
    else if (type == "no_user"){
        ui->errorMessageLabel->setText("The ID that you have enterred does not exist in our database. If you are a new User, please select the 'New Account' option and follow the instructions. Otherwise, please verify that your ID is correct and try again.");
    }
    exec();
}
