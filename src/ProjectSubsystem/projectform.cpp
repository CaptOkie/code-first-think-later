#include "projectform.h"
#include "ui_projectform.h"

ProjectForm::ProjectForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProjectForm)
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
