#include "profileform.h"
#include "ui_profileform.h"

ProfileForm::ProfileForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfileForm)
{
    ui->setupUi(this);
}

ProfileForm::~ProfileForm()
{
    delete ui;
}
