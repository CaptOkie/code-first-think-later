#include "adminlogindialog.h"
#include "ui_adminlogindialog.h"

AdminLoginDialog::AdminLoginDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::AdminLoginDialog)
{
    ui->setupUi(this);
}

AdminLoginDialog::~AdminLoginDialog()
{
    delete ui;
}
