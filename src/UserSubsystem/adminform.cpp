#include "adminform.h"
#include "ui_adminform.h"
#include <QStandardItemModel>

AdminForm::AdminForm(AdminControl& ctrl, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminForm),
    projectForm(this),
    logoutDialog(this),
    ctrl(ctrl)
{
    ui->setupUi(this);

    connect(ui->editProjectButton, &QPushButton::released, this, &AdminForm::editProject);
    connect(ui->logoutButton, &QPushButton::released, this, &AdminForm::logout);
    connect(&logoutDialog, &QDialog::finished, this, &AdminForm::logoutDialogFinished);
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

void AdminForm::logoutDialogFinished()
{
    if (logoutDialog.result() == 1 || logoutDialog.result() == 2)
    {
        close();
    }
}

void AdminForm::addTreeItem(QStringList list)
{
    QTreeWidgetItem* item = new QTreeWidgetItem(ui->projectTable, list);
    ui->projectTable->insertTopLevelItem(0, item);
}

void AdminForm::resizeTable()
{
    for (int i = 0; i < 3; i++)
        ui->projectTable->resizeColumnToContents(i);
}

void AdminForm::show(QMap<QString, Project*>& projects)
{
    ui->projectTable->clear();
    QMap<QString, Project*>::const_iterator i;
    for (i = projects.begin(); i != projects.end(); ++i)
    {
        QStringList list;
        list.append(i.value()->getName());
        list.append(QString::number(i.value()->getMinGroupSize()));
        list.append(QString::number(i.value()->getMaxGroupSize()));
        addTreeItem(list);
    }
    resizeTable();
    QMainWindow::show();
}
