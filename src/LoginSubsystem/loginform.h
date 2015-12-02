#ifndef LOGINFORM_H
#define LOGINFORM_H

#include "helpdialog.h"
#include "errordialog.h"

#include <QWidget>
#include <QPushButton>

namespace Ui {
    class LoginForm;
}

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

private:
    Ui::LoginForm *ui;
    HelpDialog helpDialog;
    ErrorDialog errorDialog;

private slots:
    void attemptLogin();
    void createNewAccount();
};

#endif // LOGINFORM_H
