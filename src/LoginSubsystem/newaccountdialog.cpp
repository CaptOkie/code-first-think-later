#include "newaccountdialog.h"
#include "ui_newaccountdialog.h"

NewAccountDialog::NewAccountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewAccountDialog)
{
    ui->setupUi(this);
}

NewAccountDialog::~NewAccountDialog()
{
    delete ui;
}

void NewAccountDialog::close()
{
    QDialog::reject();
}

void NewAccountDialog::showDialog()
{
    exec();
}
