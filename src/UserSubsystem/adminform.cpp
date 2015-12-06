#include "adminform.h"
#include "ui_adminform.h"
#include <QStandardItemModel>

#include "admincontrol.h"

AdminForm::AdminForm(AdminControl& ctrl, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::AdminForm), logoutDialog(this), ctrl(ctrl), confirmationDialog(this)
{
    ui->setupUi(this);

    connect(ui->editProjectButton, &QPushButton::clicked, this, &AdminForm::editProject);
    connect(ui->logoutButton, &QPushButton::clicked, this, &AdminForm::logout);
    connect(ui->createProjectButton, &QPushButton::clicked, this, &AdminForm::newProject);
    connect(ui->deleteProjectButton, &QPushButton::clicked, this, &AdminForm::deleteProjectDialog);
    connect(ui->viewPPIDButton, &QPushButton::clicked, this, &AdminForm::viewPPID);
    connect(&logoutDialog, &QDialog::finished, this, &AdminForm::logoutDialogFinished);
    connect(ui->projectTable, &QTreeWidget::currentItemChanged, this, &AdminForm::displayStuNames);
}

AdminForm::~AdminForm()
{
    delete ui;
}

void AdminForm::newProject()
{
    ctrl.newProjectStart();
}

void AdminForm::editProject()
{
    if (ui->projectTable->currentItem() != NULL)
    {
        ctrl.editProjectStart(ui->projectTable->currentItem()->text(0));
    }
}

void AdminForm::deleteProjectDialog()
{
    if (ui->projectTable->currentItem() != NULL)
    {
        connect(&confirmationDialog, &QDialog::accepted, this, &AdminForm::deleteProject);
        confirmationDialog.showDialog("admin");
    }
}

void AdminForm::deleteProject()
{
    QTreeWidgetItem* item = ui->projectTable->currentItem();
    if (item)
        ctrl.deleteProject(item->text(0));
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

void AdminForm::addTreeItem(QTreeWidget* tree, QStringList list)
{
    QTreeWidgetItem* item = new QTreeWidgetItem(tree, list);
    tree->insertTopLevelItem(0, item);
}

void AdminForm::resizeTable(QTreeWidget* tree)
{
    for (int i = 0; i < 3; i++)
        tree->resizeColumnToContents(i);
}

void AdminForm::displayStuNames()
{
    if (ui->projectTable->currentItem() != NULL)
    {
        ui->stuNameTable->clear();
        QString project = ui->projectTable->currentItem()->text(0);
        const QMap<int, Student*>& students = ctrl.getStuNames(project);
        QMap<int, Student*>::const_iterator i;
        for (i = students.begin(); i != students.end(); ++ i)
        {
            QStringList list;
            list.append(i.value()->getName());
            addTreeItem(ui->stuNameTable, list);
        }
        enableButtons(true);
    }
    else {
        enableButtons(false);
    }
}

void AdminForm::enableButtons(bool b)
{
    ui->deleteProjectButton->setEnabled(b);
    ui->editProjectButton->setEnabled(b);
    ui->viewPPIDButton->setEnabled(b);
}

void AdminForm::show(QMap<QString, Project*>& projects)
{
    update(projects);
    enableButtons(false);
    QMainWindow::show();
}

void AdminForm::update(QMap<QString, Project*>& projects)
{
    ui->projectTable->clear();
    QMap<QString, Project*>::const_iterator i;
    for (i = projects.begin(); i != projects.end(); ++i)
    {
        QStringList list;
        list.append(i.value()->getName());
        list.append(QString::number(i.value()->getMinGroupSize()));
        list.append(QString::number(i.value()->getMaxGroupSize()));
        addTreeItem(ui->projectTable, list);
    }
    resizeTable(ui->projectTable);
}

void AdminForm::viewPPID()
{
    if (ui->projectTable->currentItem() != NULL)
    {
        ctrl.runPPID(ui->projectTable->currentItem()->text(0));
    }
}
