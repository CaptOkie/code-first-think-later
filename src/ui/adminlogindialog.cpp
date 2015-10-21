#include "adminlogindialog.h"
#include "ui_adminlogindialog.h"

adminLoginDialog::adminLoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminLoginDialog)
{
    ui->setupUi(this);
}

adminLoginDialog::~adminLoginDialog()
{
    delete ui;
}
