#include "studentform.h"
#include "ui_studentform.h"
#include "studentcontrol.h"

StudentForm::StudentForm(StudentControl& ctrl, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentForm),
    logoutDialog(this),
    confirmationDialog(this),
    ctrl(ctrl)
{
    ui->setupUi(this);

    connect(ui->logoutButton, &QPushButton::released, this, &StudentForm::logout);
    connect(ui->editProfileButton, &QPushButton::released, this, &StudentForm::editProfile);
    connect(&logoutDialog, &QDialog::finished, this, &StudentForm::logoutDialogFinished);
    connect(ui->joinButton, &QPushButton::released, this, &StudentForm::joinProject);
    connect(ui->leaveButton, &QPushButton::released, this, &StudentForm::leaveProjectDialog);
    connect(ui->projectTable, &QTreeWidget::currentItemChanged, this, &StudentForm::jProjectSelect);
    connect(ui->projectTable2, &QTreeWidget::currentItemChanged, this, &StudentForm::lProjectSelect);
}

StudentForm::~StudentForm()
{
    delete ui;
}

void StudentForm::logout()
{
    logoutDialog.showDialog();
}

void StudentForm::setName(QString name)
{
    ui->nameLabel->setText(name);
}

void StudentForm::logoutDialogFinished()
{
    if (logoutDialog.result() == 1 || logoutDialog.result() == 2)
    {
        close();
    }
}

void StudentForm::editProfile()
{
    ctrl.editProfile();
}

void StudentForm::joinProject()
{
    if (ui->projectTable->currentItem() != NULL)
    {
        ctrl.joinProject(ui->projectTable->currentItem()->text(0));
    }
}

void StudentForm::leaveProjectDialog()
{
    if (ui->projectTable2->currentItem() != NULL)
    {
        connect(&confirmationDialog, &QDialog::accepted, this, &StudentForm::leaveProject);
        confirmationDialog.showDialog("stu");
    }
}

void StudentForm::leaveProject()
{
    ctrl.leaveProject(ui->projectTable2->currentItem()->text(0));
}

void StudentForm::addTreeItem(QTreeWidget* tree, QStringList list)
{
    QTreeWidgetItem* item = new QTreeWidgetItem(tree, list);
    tree->insertTopLevelItem(0, item);
}

void StudentForm::resizeTable(QTreeWidget* tree)
{
    for (int i = 0; i < 3; i++)
        tree->resizeColumnToContents(i);
}

void StudentForm::show(const QMap<QString, Project*>& unjoinedProjects, const QMap<QString, Project*>& joinedProjects)
{
    ui->projectTable->clear();
    QMap<QString, Project*>::const_iterator i;
    for (i = unjoinedProjects.begin(); i != unjoinedProjects.end(); ++i)
    {
        QStringList list;
        list.append(i.value()->getName());
        addTreeItem(ui->projectTable, list);
    }
    resizeTable(ui->projectTable);

    ui->projectTable2->clear();
    QMap<QString, Project*>::const_iterator j;
    for (j = joinedProjects.begin(); j != joinedProjects.end(); ++j)
    {
        QStringList list;
        list.append(j.value()->getName());
        addTreeItem(ui->projectTable2, list);
    }
    resizeTable(ui->projectTable2);
    enableButton("join", false);
    enableButton("leave", false);
    QMainWindow::show();
}

void StudentForm::jProjectSelect()
{
    if (ui->projectTable->currentItem() != NULL)
        enableButton("join", true);
    else
        enableButton("join", false);
}

void StudentForm::lProjectSelect()
{
    if (ui->projectTable2->currentItem() != NULL)
        enableButton("leave", true);
    else
        enableButton("leave", false);

}

void StudentForm::enableButton(QString type, bool b)
{
    if (type == "join")
    {
        ui->joinButton->setEnabled(b);
    }
    else if (type == "leave")
    {
        ui->leaveButton->setEnabled(b);
    }
}
