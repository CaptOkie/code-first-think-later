#include "adminform.h"
#include "ui_adminform.h"
#include <QStandardItemModel>

AdminForm::AdminForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminForm),
    projectForm(this),
    logoutDialog(this)
{
    ui->setupUi(this);

    connect(ui->editProjectButton, &QPushButton::released, this, &AdminForm::editProject);
    connect(ui->logoutButton, &QPushButton::released, this, &AdminForm::logout);
    for (int i = 0; i < 3; i++)
        ui->projectTable->resizeColumnToContents(i);
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

void AdminForm::logout()
{
    logoutDialog.showDialog();
}

QTreeWidget* AdminForm::getTreeWidget()
{
    return ui->projectTable;
}
