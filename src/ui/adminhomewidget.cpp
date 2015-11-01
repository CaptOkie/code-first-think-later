#include "adminhomewidget.h"
#include "ui_adminhomewidget.h"

#include "../db/project.h"
#include <QList>
#include <QTreeWidgetItem>

AdminHomeWidget::AdminHomeWidget(Storage& db, User* currUser, QWidget *parent)
    : QWidget(parent), ui(new Ui::AdminHomeWidget), detailsDialog(this),
      db(db), currUser(currUser)
{
    ui->setupUi(this);
    ui->nameLabel->setText(currUser->getName());
    ui->numberLabel->setText(QString::number(currUser->getId()));
    loadProjects();

    connect(ui->newBtn, &QPushButton::clicked, &detailsDialog, &QDialog::show);
}

AdminHomeWidget::~AdminHomeWidget()
{
    delete ui;
    delete currUser;
}

void AdminHomeWidget::loadProjects() {
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
