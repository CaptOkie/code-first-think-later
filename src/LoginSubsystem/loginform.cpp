#include "loginform.h"
#include "ui_loginform.h"

LoginForm::LoginForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginForm),
    helpDialog(this)
{
    ui->setupUi(this);

    connect(ui->askHelpButton, &QPushButton::released, &helpDialog, &HelpDialog::showDialog);
    connect(ui->createAccountButton, &QPushButton::released, this, &LoginForm::createNewAccount);
    connect(ui->loginButton, &QPushButton::released, this, &LoginForm::attemptLogin);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::attemptLogin()
{

}

void LoginForm::createNewAccount()
{

}
