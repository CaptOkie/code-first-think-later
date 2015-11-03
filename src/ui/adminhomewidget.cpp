#include "adminhomewidget.h"
#include "ui_adminhomewidget.h"

#include <QTreeWidgetItem>
#include "../db/project.h"

AdminHomeWidget::AdminHomeWidget(Storage& db, User* currUser, QWidget *parent)
    : QWidget(parent), ui(new Ui::AdminHomeWidget), detailsDialog(db, this), db(db), currUser(currUser)
{
    ui->setupUi(this);
    ui->nameLabel->setText(currUser->getName());
    ui->numberLabel->setText(QString::number(currUser->getId()));
    loadProjects();

    connect(ui->newBtn, &QPushButton::clicked, this, &AdminHomeWidget::newProject);
    connect(ui->editBtn, &QPushButton::clicked, this, &AdminHomeWidget::editProject);
    connect(ui->deleteBtn, &QPushButton::clicked, this, &AdminHomeWidget::deleteProject);
    connect(&detailsDialog, &ProjectDetailsDialog::projectUpdated, this, &AdminHomeWidget::loadProjects);
}

AdminHomeWidget::~AdminHomeWidget()
{
    delete ui;
    delete currUser;
}

void AdminHomeWidget::newProject()
{
    detailsDialog.showProject(NULL);
}

void AdminHomeWidget::editProject()
{
    if (ui->projectTreeWidget->currentItem() != NULL) {
        QList<Project>* projects = NULL;
        QString project = ui->projectTreeWidget->currentItem()->text(0);
        db.getProjects(&projects, project);

        detailsDialog.showProject(&(projects->first()));
        delete projects;
    }
}

void AdminHomeWidget::loadProjects()
{
    ui->projectTreeWidget->clear();
    QList<Project>* projects = 0;
    db.getProjects(&projects);

    QList<Project>::const_iterator it;
    for(it = projects->begin(); it != projects->end(); ++it) {
        QStringList list;
        const Project& p = *it;
        list.append(p.getName());
        list.append(QString::number(p.getGroupSize().getMin()));
        list.append(QString::number(p.getGroupSize().getMax()));
        new QTreeWidgetItem(ui->projectTreeWidget, list);
    }

    delete projects;
}

void AdminHomeWidget::deleteProject()
{
    if (ui->projectTreeWidget->currentItem() != NULL) {
        QString project = ui->projectTreeWidget->currentItem()->text(0);
        db.removeProject(project);
        loadProjects();
    }
}
