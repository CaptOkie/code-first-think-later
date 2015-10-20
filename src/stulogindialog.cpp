#include "stulogindialog.h"
#include "ui_stulogindialog.h"

StuLoginDialog::StuLoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StuLoginDialog)
{
    ui->setupUi(this);
}

StuLoginDialog::~StuLoginDialog()
{
    delete ui;
}
