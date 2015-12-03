#include "profileform.h"
#include "ui_profileform.h"
#include "profilecontrol.h"


ProfileForm::ProfileForm(ProfileControl& ctrl, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfileForm),
    ctrl(ctrl)
{
    ui->setupUi(this);
}

ProfileForm::~ProfileForm()
{
    delete ui;
}

void ProfileForm::setName(Student* stu)
{
    ui->nameLabel->setText(stu->getName());
}
