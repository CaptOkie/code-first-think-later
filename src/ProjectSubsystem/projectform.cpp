#include "projectform.h"
#include "ui_projectform.h"

#include "projectcontrol.h"

ProjectForm::ProjectForm(ProjectControl& ctrl, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProjectForm),
    ctrl(ctrl)
{
    ui->setupUi(this);
}

ProjectForm::~ProjectForm()
{
    delete ui;
}

void ProjectForm::close()
{
    QDialog::reject();
}

void ProjectForm::showDialog()
{
    exec();
}

void ProjectForm::setName(QString name)
{
    ui->nameLabel->setText(name);
}

void ProjectForm::setValue(QString type, int value)
{
    if (type == "min")
    {
        ui->minGroupSpinBox->setValue(value);
    }
    else if (type == "max")
    {
        ui->maxGroupSpinBox->setValue(value);
    }
}
