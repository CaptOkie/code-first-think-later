#include "adminform.h"
#include "ui_adminform.h"

AdminForm::AdminForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminForm),
    projectForm(this)
{
    ui->setupUi(this);

    connect(ui->editProjectButton, &QPushButton::released, this, &AdminForm::editProject);
}

AdminForm::~AdminForm()
{
    delete ui;
}

void AdminForm::editProject()
{

}

void AdminForm::setName(QString name)
{
    ui->nameLabel->setText(name);
}
