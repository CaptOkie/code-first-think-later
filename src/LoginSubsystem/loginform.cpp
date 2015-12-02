#include "loginform.h"
#include "ui_loginform.h"

#include "logincontrol.h"

LoginForm::LoginForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginForm),
    helpDialog(this),
    errorDialog(this)
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
    QString userInput = ui->userIDInput->text();
    QString errorMessage;
    if (userInput.length() > 0){
        LoginControl control;
        if (control.start(userInput)){
            close();
        }
        else {
            errorMessage = "no_user";
            errorDialog.showDialog(errorMessage);
        }
    }
    else {
        errorMessage = "no_input";
        errorDialog.showDialog(errorMessage);
    }
}

void LoginForm::createNewAccount()
{

}
