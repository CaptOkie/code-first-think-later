#include "loginform.h"
#include "ui_loginform.h"
#include "logincontrol.h"

LoginForm::LoginForm(LoginControl& ctrl, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginForm),
    helpDialog(this),
    errorDialog(this),
    newAcctDialog(this),
    ctrl(ctrl)
{
    ui->setupUi(this);

    connect(ui->askHelpButton, &QPushButton::clicked, &helpDialog, &HelpDialog::showDialog);
    connect(ui->createAccountButton, &QPushButton::clicked, this, &LoginForm::createNewAccount);
    connect(ui->studentLoginButton, &QPushButton::clicked, this, &LoginForm::studentLogin);
    connect(ui->adminLoginButton, &QPushButton::clicked, this, &LoginForm::adminLogin);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::studentLogin()
{
    QString errorMessage;
    QString userInput = ui->userIDInput->text();

    if (userInput.length() > 0){
        if (ctrl.studentLogin(userInput.toInt())){
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

void LoginForm::adminLogin()
{
    QString errorMessage;
    QString userInput = ui->userIDInput->text();

    if (userInput.length() > 0){
        if (ctrl.adminLogin(userInput.toInt())){
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
    newAcctDialog.showDialog();
}

void LoginForm::show()
{
    setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            size(),
            qApp->desktop()->availableGeometry()
        )
    );
    QMainWindow::show();
}

void LoginForm::setGIF(QMovie* gif)
{
    ui->gifLabel->setMovie(gif);
    gif->start();
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &LoginForm::removeGIF);
    timer->start(1550);
}

void LoginForm::removeGIF()
{
    ui->gifLabel->hide();
}
