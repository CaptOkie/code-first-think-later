#ifndef LOGINFORM_H
#define LOGINFORM_H

#include "helpdialog.h"
#include "errordialog.h"

#include <QWidget>
#include <QPushButton>

#include <QMainWindow>

namespace Ui {
class LoginForm;
}

class LoginForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = 0);
    ~LoginForm();
    Ui::LoginForm *ui;
private:
    HelpDialog helpDialog;
    ErrorDialog errorDialog;

private slots:
    void adminLogin();
    void studentLogin();
    void createNewAccount();
};

#endif // LOGINFORM_H
