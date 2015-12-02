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
    connect(&logoutDialog, SIGNAL(finished (int)), this, SLOT(logoutDialogFinished(int)));
    //connect(&logoutDialog, &);
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

void AdminForm::logoutDialogFinished(int result)
{
    if (result == QDialog::Accepted || result == 13)
    {
        close();
    }
}

QTreeWidget* AdminForm::getTreeWidget()
{
    return ui->projectTable;
}

void AdminForm::addTreeItem(QStringList list)
{
    QTreeWidgetItem* item = new QTreeWidgetItem(ui->projectTable, list);
    ui->projectTable->insertTopLevelItem(0, item);
}
