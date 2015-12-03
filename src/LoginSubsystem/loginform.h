#ifndef LOGINFORM_H
#define LOGINFORM_H


#include "helpdialog.h"
#include "errordialog.h"
#include "newaccountdialog.h"

#include <QWidget>
#include <QPushButton>
#include <QMovie>
#include <QMainWindow>

namespace Ui {
    class LoginForm;
}

class LoginControl;

class LoginForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginForm(LoginControl& ctrl, QWidget *parent = 0);
    ~LoginForm();

    void show();
    void setGIF(QMovie*);

private:
    Ui::LoginForm *ui;
    HelpDialog helpDialog;
    ErrorDialog errorDialog;
    NewAccountDialog newAcctDialog;
    LoginControl& ctrl;

public slots:
    void removeGIF();

private slots:
    void adminLogin();
    void studentLogin();
    void createNewAccount();
};

#endif // LOGINFORM_H
