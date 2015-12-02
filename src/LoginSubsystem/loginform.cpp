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
    connect(ui->studentLoginButton, &QPushButton::released, this, &LoginForm::studentLogin);
    connect(ui->adminLoginButton, &QPushButton::released, this, &LoginForm::adminLogin);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::studentLogin()
{
    /*QString userInput = ui->userIDInput->text();
    QString errorMessage;

    if (userInput.length() > 0){
        bool result = loginControl.studentLogin(userInput);
        if (result){
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
    }*/
}

void LoginForm::adminLogin()
{
    /*QString userInput = ui->userIDInput->text(userInput);
    QString errorMessage;

    if (userInput.length() > 0){
        bool result = loginControl::adminLogin();
        if (result){
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
    }*/
}

void LoginForm::createNewAccount()
{

}
