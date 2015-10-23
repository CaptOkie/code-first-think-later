#include "adminlogindialog.h"
#include "ui_adminlogindialog.h"
#include "errordialog.h"

AdminLoginDialog::AdminLoginDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::AdminLoginDialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(handleCancelButton()));
}

AdminLoginDialog::~AdminLoginDialog()
{
    delete ui;
}

void AdminLoginDialog::handleCancelButton()
{
    QDialog* errorDialog = new ErrorDialog(parentWidget());
    errorDialog->show();
}
