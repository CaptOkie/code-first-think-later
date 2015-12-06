#include "projectform.h"
#include "ui_projectform.h"

#include "projectcontrol.h"

ProjectForm::ProjectForm(ProjectControl& ctrl, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProjectForm),
    errorDialog(this),
    ctrl(ctrl)
{
    ui->setupUi(this);

    connect(ui->cancelButton, &QPushButton::released, this, &ProjectForm::close);
    connect(ui->saveButton, &QPushButton::released, this, &ProjectForm::save);
}

ProjectForm::~ProjectForm()
{
    delete ui;
}

void ProjectForm::close()
{
    QDialog::reject();
}

void ProjectForm::save()
{
    if (ctrl.checkValues(ui->minGroupSpinBox->text(), ui->maxGroupSpinBox->text()))
    {
        ctrl.saveProject(ui->projectNameEdit->text(), ui->minGroupSpinBox->text(), ui->maxGroupSpinBox->text());
        QDialog::accept();
    }
    else
    {
        errorDialog.showDialog();
    }
}

void ProjectForm::showDialog()
{
    exec();
}

void ProjectForm::setName(QString name)
{
    if (name == "<New Project>")
    {
        ui->nameLabel->setText(name);
        ui->projectNameEdit->setText("");
    }
    else
    {
        ui->nameLabel->setText(name);
        ui->projectNameEdit->setText(name);
    }
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
