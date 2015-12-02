#include "logoutdialog.h"
#include "ui_logoutdialog.h"

LogoutDialog::LogoutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogoutDialog)
{
    ui->setupUi(this);

    connect(ui->noButton, &QPushButton::released, this, &LogoutDialog::close);
    connect(ui->yesButton, &QPushButton::released, this, &LogoutDialog::logout);
    connect(ui->exitButton, &QPushButton::released, this, &LogoutDialog::exit);
}

LogoutDialog::~LogoutDialog()
{
    delete ui;
}

void LogoutDialog::close()
{
    QDialog::reject();
}

void LogoutDialog::logout()
{
    QDialog::done(0);
}

void LogoutDialog::exit()
{
    QDialog::done(1);
}

void LogoutDialog::showDialog()
{
    exec();
}
